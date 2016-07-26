--- src/aomodule.h.orig	2003-07-24 06:58:07 UTC
+++ src/aomodule.h
@@ -9,6 +9,7 @@
 typedef struct {
   PyObject_HEAD
   ao_device *dev;
+  uint32_t driver_id;
 } ao_Object;
 
 static PyObject *Py_aoError;
