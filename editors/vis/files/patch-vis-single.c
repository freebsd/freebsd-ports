--- vis-single.c.orig	2024-06-11 22:03:34 UTC
+++ vis-single.c
@@ -29,7 +29,7 @@
 
 #ifndef VIS_TERMINFO
 #define VIS_TERMINFO "/etc/terminfo:/lib/terminfo:/usr/share/terminfo:" \
-	"/usr/lib/terminfo:/usr/local/share/terminfo:/usr/local/lib/terminfo"
+	"/usr/lib/terminfo:%%PREFIX%%/share/terminfo:%%PREFIX%%/lib/terminfo"
 #endif
 
 static lzma_stream strm = LZMA_STREAM_INIT;
