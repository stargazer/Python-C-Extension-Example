#include <Python.h>

/*
 * Module method definition.
 * This is the code that will be invoked by `hello.say_hello`.
 */
static PyObject* say_hello(PyObject* self, PyObject* args)
{
    const char* name;

    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    printf("Hello %s!\n", name);

    Py_RETURN_NONE;
}

/*
 * Method definition.
 *
 * ml_name: Method name
 * ml_meth: Pointer to the method implementation
 * ml_flags: Flags indicating special features of the method
 * ml_doc: Method's docstring
 */
static PyMethodDef HelloMethods[] =
{
     {"say_hello", say_hello, METH_VARARGS, "Greet somebody."},
     {NULL, NULL, 0, NULL}
};

/*
 * Module initialization.
 * Python calls this method when importing the extension.
 */
PyMODINIT_FUNC inithello(void)
{
     (void) Py_InitModule("hello", HelloMethods);
}
