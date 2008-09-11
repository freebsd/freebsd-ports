--- Objects/tupleobject.c.orig	2006-03-17 20:04:15.000000000 +0100
+++ Objects/tupleobject.c
@@ -60,11 +60,12 @@ PyTuple_New(register int size)
 		int nbytes = size * sizeof(PyObject *);
 		/* Check for overflow */
 		if (nbytes / sizeof(PyObject *) != (size_t)size ||
-		    (nbytes += sizeof(PyTupleObject) - sizeof(PyObject *))
-		    <= 0)
+		    (nbytes > INT_MAX - sizeof(PyTupleObject) - sizeof(PyObject *)))
 		{
 			return PyErr_NoMemory();
 		}
+		nbytes += sizeof(PyTupleObject) - sizeof(PyObject *);
+
 		op = PyObject_GC_NewVar(PyTupleObject, &PyTuple_Type, size);
 		if (op == NULL)
 			return NULL;
