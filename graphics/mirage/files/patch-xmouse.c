--- xmouse.c.orig	2007-11-27 14:26:18 UTC
+++ xmouse.c
@@ -37,7 +37,8 @@ PyObject* xmouse_geometry(PyObject* self
 
 PyMethodDef methods[] =
 {
-    {"geometry", xmouse_geometry, METH_VARARGS},
+    {"geometry", xmouse_geometry, METH_VARARGS, NULL},
+    {NULL, NULL, 0, NULL}
 };
 
 void initxmouse(void)
