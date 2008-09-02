--- ./coders/fpx.c.orig	2007-11-05 22:03:47.000000000 -0500
+++ ./coders/fpx.c	2008-09-02 08:05:29.000000000 -0400
@@ -181,15 +181,15 @@
 
   unsigned int
     status,
-    subimage;
-
-  unsigned long
+    subimage,
     height,
-    memory_limit,
     tile_width,
     tile_height,
     width;
 
+  size_t
+    memory_limit;
+
   /*
     Open image.
   */
