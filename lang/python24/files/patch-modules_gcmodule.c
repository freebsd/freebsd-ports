--- Modules/gcmodule.c.orig	2006-09-28 19:08:01.000000000 +0200
+++ Modules/gcmodule.c
@@ -1249,7 +1249,10 @@ PyObject *
 _PyObject_GC_Malloc(size_t basicsize)
 {
 	PyObject *op;
-	PyGC_Head *g = PyObject_MALLOC(sizeof(PyGC_Head) + basicsize);
+	PyGC_Head *g;
+ 	if (basicsize > INT_MAX - sizeof(PyGC_Head))
+ 		return PyErr_NoMemory();
+	g = PyObject_MALLOC(sizeof(PyGC_Head) + basicsize);
 	if (g == NULL)
 		return PyErr_NoMemory();
 	g->gc.gc_refs = GC_UNTRACKED;
@@ -1291,6 +1294,8 @@ _PyObject_GC_Resize(PyVarObject *op, int
 {
 	const size_t basicsize = _PyObject_VAR_SIZE(op->ob_type, nitems);
 	PyGC_Head *g = AS_GC(op);
+ 	if (basicsize > INT_MAX - sizeof(PyGC_Head))
+ 		return (PyVarObject *)PyErr_NoMemory();
 	g = PyObject_REALLOC(g,  sizeof(PyGC_Head) + basicsize);
 	if (g == NULL)
 		return (PyVarObject *)PyErr_NoMemory();
