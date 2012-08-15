
$FreeBSD$

--- c_src/esdl_driver.c.orig
+++ c_src/esdl_driver.c
@@ -34,11 +34,16 @@
 
 #define TEMP_BINARY_SIZE 512
 
+#if ERL_DRV_EXTENDED_MAJOR_VERSION < 2
+typedef int ErlDrvSizeT;
+typedef int ErlDrvSSizeT;
+#endif
+
 static ErlDrvData sdl_driver_start(ErlDrvPort port, char *buff);
 static void sdl_driver_stop(ErlDrvData handle);
 static void sdl_driver_finish(void);
-static int sdl_driver_control(ErlDrvData handle, unsigned int command, 
-			      char* buf, int count, char** res, int res_size);
+static ErlDrvSSizeT sdl_driver_control(ErlDrvData handle, unsigned int command, 
+			      char* buf, ErlDrvSizeT count, char** res, ErlDrvSizeT res_size);
 static void standard_outputv(ErlDrvData drv_data, ErlIOVec *ev);
 
 /*
@@ -59,6 +64,17 @@
     sdl_driver_control,    /* F_PTR control, port_control callback */
     NULL,                  /* F_PTR timeout, reserved */
     standard_outputv,	   /* F_PTR outputv, reserved */
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
 
 DRIVER_INIT(sdl_driver)
@@ -148,9 +164,9 @@
 {
 }
 
-static int
+static ErlDrvSSizeT
 sdl_driver_control(ErlDrvData handle, unsigned op,
-		   char* buf, int count, char** res, int res_size)
+		   char* buf, ErlDrvSizeT count, char** res, ErlDrvSizeT res_size)
 {
   sdl_data* sd = (sdl_data *) handle;
   sdl_fun func;
