--- bio2jack.c.orig	Sat Jun 17 18:58:16 2006
+++ bio2jack.c	Thu Dec  7 12:51:17 2006
@@ -2512,11 +2512,12 @@
   {
     drv = &outDev[x];
 
+    memset(drv, 0, sizeof(jack_driver_t));
+
     pthread_mutex_init(&drv->mutex, NULL);
 
     getDriver(x);
 
-    memset(drv, 0, sizeof(jack_driver_t));
     drv->volumeEffectType = linear;
     drv->deviceID = x;
 
