
$FreeBSD$

--- vcut/vcut.c.orig	Tue Jun 17 01:19:13 2003
+++ vcut/vcut.c	Tue Jun 17 01:20:27 2003
@@ -26,7 +26,7 @@
 #ifdef _WIN32
 #define FORMAT_INT64 "%I64d"
 #else
-#define FORMAT_INT64 "%Ld"
+#define FORMAT_INT64 "%lld"
 #endif
 
 static vcut_packet *save_packet(ogg_packet *packet)
