--- src/prof/gmon.h.orig	2007-10-04 01:06:18.000000000 +0200
+++ src/prof/gmon.h	2007-10-04 01:06:48.000000000 +0200
@@ -119,7 +119,7 @@
 
 struct tostruct
   {
-    char *selfpc;
+    uint32_t selfpc;
     int count;
     unsigned short link;
   };
