--- src/libs/xpcom18a4/python/src/PyXPCOM.h.orig	2016-09-12 16:20:10 UTC
+++ src/libs/xpcom18a4/python/src/PyXPCOM.h
@@ -286,7 +286,11 @@ public:
 	static int Py_setattr(PyObject *op, char *name, PyObject *v);
 	static int Py_cmp(PyObject *ob1, PyObject *ob2);
 	static PyObject *Py_richcmp(PyObject *ob1, PyObject *ob2, int op);
+#if PY_VERSION_HEX < 0x03020000
 	static long Py_hash(PyObject *self);
+#else
+	static Py_hash_t Py_hash(PyObject *self);
+#endif
 };
 
 //////////////////////////////////////////////////////////////////////////
@@ -442,7 +446,11 @@ public:
 #endif
 	static PyObject *PyTypeMethod_richcompare(PyObject *self, PyObject *ob, int op);
 	static PyObject *PyTypeMethod_repr(PyObject *self);
+#if PY_VERSION_HEX < 0x03020000
 	static long PyTypeMethod_hash(PyObject *self);
+#else
+	static Py_hash_t PyTypeMethod_hash(PyObject *self);
+#endif
 	static PyObject *PyTypeMethod_str(PyObject *self);
 	static void PyTypeMethod_dealloc(PyObject *self);
 	static NS_EXPORT_STATIC_MEMBER_(PyTypeObject) type;
