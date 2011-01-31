--- plugins/dfcdrom/cdr.h.orig	2011-01-27 06:48:33.209766794 +0100
+++ plugins/dfcdrom/cdr.h	2011-01-27 06:52:51.789416162 +0100
@@ -78,7 +78,7 @@
 #define CD_FRAMESIZE_SUB	96
 
 #if defined (__FreeBSD__)
-#define DEV_DEF		"/dev/cd0"
+#define DEV_DEF		"%%DVD_DEVICE%%"
 #else
 #define DEV_DEF		""
 #endif
