
$FreeBSD$

--- plugins_src/accel/perlin_noise_drv.c.orig
+++ plugins_src/accel/perlin_noise_drv.c
@@ -22,6 +22,11 @@
 #include <math.h>
 #include <string.h>
 
+#if ERL_DRV_EXTENDED_MAJOR_VERSION < 2
+typedef int ErlDrvSizeT;
+typedef int ErlDrvSSizeT;
+#endif
+
 #define PNOISE3 3
 #define SNOISE1 4
 #define SNOISE2 5
@@ -57,9 +62,9 @@
  */
 static ErlDrvData perlin_noise_start(ErlDrvPort port, char *buff);
 static void perlin_noise_stop(ErlDrvData handle);
-static int control(ErlDrvData handle, unsigned int command, 
-                   char* buff, int count, 
-                   char** res, int res_size);
+static ErlDrvSSizeT control(ErlDrvData handle, unsigned int command, 
+                   char* buff, ErlDrvSizeT count, 
+                   char** res, ErlDrvSizeT res_size);
 
 /*
  * Internal routines
@@ -82,7 +87,18 @@
    NULL,                  /* void * that is not used (BC) */
    control,               /* F_PTR control, port_control callback */
    NULL,                  /* F_PTR timeout, driver_set_timer callback */
-   NULL                   /* F_PTR outputv, reserved */
+   NULL,                  /* F_PTR outputv, reserved */
+   NULL,
+   NULL,
+   NULL,
+   NULL,
+   ERL_DRV_EXTENDED_MARKER,
+   ERL_DRV_EXTENDED_MAJOR_VERSION,
+   ERL_DRV_EXTENDED_MINOR_VERSION,
+   0,
+   NULL,
+   NULL,
+   NULL
 };
 
 /*
@@ -114,9 +130,9 @@
    
 }
 
-static int control(ErlDrvData handle, unsigned int command,
-		   char* buff, int count, 
-		   char** res, int res_size)
+static ErlDrvSSizeT control(ErlDrvData handle, unsigned int command,
+		   char* buff, ErlDrvSizeT count, 
+		   char** res, ErlDrvSizeT res_size)
 {
    ErlDrvBinary* bin;
 
