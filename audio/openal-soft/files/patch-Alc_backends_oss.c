--- Alc/backends/oss.c.orig	2012-03-28 17:55:17.000000000 +0200
+++ Alc/backends/oss.c	2012-04-22 14:13:19.000000000 +0200
@@ -511,7 +511,7 @@
         {
 #ifdef HAVE_STAT
             struct stat buf;
-            if(stat(oss_device, &buf) == 0)
+            if(stat(oss_driver, &buf) == 0)
 #endif
                 AppendAllDeviceList(oss_device);
         }
