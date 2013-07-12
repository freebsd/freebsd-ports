
$FreeBSD$

--- plugins_src/accel/wings_pick_drv.c.orig
+++ plugins_src/accel/wings_pick_drv.c
@@ -20,14 +20,19 @@
 #endif
 #include <string.h>
 
+#if ERL_DRV_EXTENDED_MAJOR_VERSION < 2
+typedef int ErlDrvSizeT;
+typedef int ErlDrvSSizeT;
+#endif
+
 /*
  * Interface routines.
  */
 static ErlDrvData wings_file_start(ErlDrvPort port, char *buff);
 static void wings_file_stop(ErlDrvData handle);
-static int control(ErlDrvData handle, unsigned int command,
-                   char* buff, int count,
-                   char** res, int res_size);
+static ErlDrvSSizeT control(ErlDrvData handle, unsigned int command,
+                   char* buff, ErlDrvSizeT count,
+                   char** res, ErlDrvSizeT res_size);
 static void outputv(ErlDrvData drv_data, ErlIOVec* ev);
 
 /*
@@ -47,7 +52,18 @@
     NULL,                  /* void * that is not used (BC) */
     control,               /* F_PTR control, port_control callback */
     NULL,                  /* F_PTR timeout, driver_set_timer callback */
-    outputv                /* F_PTR outputv, reserved */
+    outputv,                /* F_PTR outputv, reserved */
+    NULL,
+    NULL,
+    NULL,
+    NULL,
+    ERL_DRV_EXTENDED_MARKER,
+    ERL_DRV_EXTENDED_MAJOR_VERSION,
+    ERL_DRV_EXTENDED_MINOR_VERSION,
+    0,
+    NULL,
+    NULL,
+    NULL
 };
 
 struct vertex_struct {
@@ -107,14 +123,14 @@
  * Handle commands.
  */
 
-static int
+static ErlDrvSSizeT
 control(ErlDrvData handle, unsigned int command,
-        char* buf, int count,
-        char** res, int res_size)
+        char* buf, ErlDrvSizeT count,
+        char** res, ErlDrvSizeT res_size)
 {
   switch (command) {
   case 0: {			/* Define matrix */
-    memcpy((void *) m, (void *) buf, count);
+    memcpy((void *) m, (void *) buf, (size_t) count);
 #if 0
     {
       int i, j;
