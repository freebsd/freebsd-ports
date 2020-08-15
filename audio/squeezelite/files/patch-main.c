--- main.c.orig	2020-06-07 11:03:18 UTC
+++ main.c
@@ -51,7 +51,7 @@
 #else
 #define CODECS_DSD  ""
 #endif
-#define CODECS_MP3  " (mad,mpg for specific mp3 codec)"
+#define CODECS_MP3  ""
 
 #define CODECS CODECS_BASE CODECS_AAC CODECS_FF CODECS_OPUS CODECS_DSD CODECS_MP3
 
