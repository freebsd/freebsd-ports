--- src/utf.h.orig	2014-10-13 20:43:43.714736504 +0800
+++ src/utf.h	2014-10-13 20:43:55.760735241 +0800
@@ -16,6 +16,8 @@
 #include <stdint.h>
 #endif
 
+#include <sys/types.h>
+
 int utf8_encode(int32_t codepoint, char *buffer, size_t *size);
 
 size_t utf8_check_first(char byte);
