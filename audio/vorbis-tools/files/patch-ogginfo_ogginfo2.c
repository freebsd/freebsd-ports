
$FreeBSD$

--- ogginfo/ogginfo2.c.orig	Tue Jun 17 01:19:29 2003
+++ ogginfo/ogginfo2.c	Tue Jun 17 01:20:35 2003
@@ -27,7 +27,7 @@
 #ifdef _WIN32
 #define INT64FORMAT "%I64d"
 #else
-#define INT64FORMAT "%Ld"
+#define INT64FORMAT "%lld"
 #endif
 
 struct vorbis_release {
