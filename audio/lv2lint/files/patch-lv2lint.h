--- lv2lint.h.orig	2019-05-04 19:51:19 UTC
+++ lv2lint.h
@@ -38,7 +38,7 @@
 #	include <curl/curl.h>
 #endif
 
-#define __unused __attribute__((unused))
+//#define __unused __attribute__((unused))
 
 typedef enum _ansi_color_t {
 	ANSI_COLOR_BOLD,
