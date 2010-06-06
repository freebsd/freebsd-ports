--- src/aomodule.h.orig	2010-06-06 18:45:10.000000000 +0200
+++ src/aomodule.h	2010-06-06 18:45:25.000000000 +0200
@@ -9,6 +9,7 @@
 typedef struct {
   PyObject_HEAD
   ao_device *dev;
+  uint32_t driver_id;
 } ao_Object;
 
 static PyObject *Py_aoError;
