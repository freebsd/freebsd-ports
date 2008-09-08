--- Objects/tupleobject.c.orig	2006-08-12 18:03:09.000000000 +0100
+++ Objects/tupleobject.c	2008-08-30 10:16:13.000000000 +0100
@@ -60,11 +60,12 @@
 		Py_ssize_t nbytes = size * sizeof(PyObject *);
 		/* Check for overflow */
 		if (nbytes / sizeof(PyObject *) != (size_t)size ||
-		    (nbytes += sizeof(PyTupleObject) - sizeof(PyObject *))
-		    <= 0)
+		    (nbytes > PY_SSIZE_T_MAX - sizeof(PyTupleObject) - sizeof(PyObject *)))
 		{
 			return PyErr_NoMemory();
 		}
+		nbytes += sizeof(PyTupleObject) - sizeof(PyObject *);
+
 		op = PyObject_GC_NewVar(PyTupleObject, &PyTuple_Type, size);
 		if (op == NULL)
 			return NULL;
