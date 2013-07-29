--- src/prof/gmon.h.orig	2007-10-04 01:06:18.000000000 +0200
+++ src/prof/gmon.h	2007-10-04 01:06:48.000000000 +0200
@@ -29,6 +29,8 @@
 #ifndef gmon_h
 #define gmon_h
 
+#include <inttypes.h>
+
 /* Size of the 4.4BSD gmon header */
 #define GMON_HDRSIZE_BSD44_32 (4 + 4 + 4 + 4 + 4 + (3 * 4))
 #define GMON_HDRSIZE_BSD44_64 (8 + 8 + 4 + 4 + 4 + (3 * 4))
@@ -119,7 +121,7 @@
 
 struct tostruct
   {
-    char *selfpc;
+    uint32_t selfpc;
     int count;
     unsigned short link;
   };
