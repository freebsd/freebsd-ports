--- src/dyn_bsd.c.dist	Wed Dec 26 06:37:11 2001
+++ src/dyn_bsd.c	Wed Dec 26 06:39:24 2001
@@ -77,3 +77,3 @@
   *pvFHandle = 0;
-  *pvFHandle = dlsym( pvLHandle, pcFunctionName );
+  *pvFHandle = dlsym( pvLHandle, pcFunction );
 
