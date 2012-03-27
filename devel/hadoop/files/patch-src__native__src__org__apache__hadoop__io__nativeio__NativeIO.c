--- src/native/src/org/apache/hadoop/io/nativeio/NativeIO.c.orig	2011-08-10 13:43:50.000000000 +0200
+++ src/native/src/org/apache/hadoop/io/nativeio/NativeIO.c	2011-08-10 13:44:32.000000000 +0200
@@ -188,7 +188,7 @@
   if (flags & O_CREAT) {
     fd = open(path, flags, mode);
   } else {
-    fd = open(path, flags);
+    fd = open(path, flags | O_CREAT);
   }
 
   if (fd == -1) {
