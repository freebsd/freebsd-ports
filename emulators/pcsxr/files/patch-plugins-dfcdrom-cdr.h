--- plugins/dfcdrom/cdr.h.orig	2017-02-18 21:40:07 UTC
+++ plugins/dfcdrom/cdr.h
@@ -104,7 +104,7 @@ struct cdrom_msf {
 #define CD_FRAMESIZE_SUB	96
 
 #if defined (__FreeBSD__)
-#define DEV_DEF		"/dev/cd0"
+#define DEV_DEF		"%%DVD_DEVICE%%"
 #else
 #define DEV_DEF		""
 #endif
