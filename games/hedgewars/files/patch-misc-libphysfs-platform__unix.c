--- misc/libphysfs/platform_unix.c.orig	2013-05-31 00:07:37.000000000 +0400
+++ misc/libphysfs/platform_unix.c	2013-06-17 05:41:06.249112731 +0400
@@ -193,7 +193,7 @@
 
         if (access(exe, X_OK) == 0)  /* Exists as executable? We're done. */
         {
-            exe[size - binlen] = '\0'; /* chop off filename, leave '/' */
+            exe[size - binlen - 1] = '\0'; /* chop off filename, leave '/' */
             return exe;
         } /* if */
 
