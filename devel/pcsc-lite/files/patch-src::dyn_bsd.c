--- src/dyn_bsd.c.dist	Thu Nov  8 16:40:00 2001
+++ src/dyn_bsd.c	Thu Nov  8 16:40:21 2001
@@ -74,3 +74,3 @@
   *pvFHandle = 0;
-  *pvFHandle = dlsym( pvLHandle, pcFunctionName );
+  *pvFHandle = dlsym( pvLHandle, pcFunction );
 
