--- src/utf.h.orig	2015-03-07 07:02:40 UTC
+++ src/utf.h
@@ -16,6 +16,8 @@
 #include <stdint.h>
 #endif
 
+#include <sys/types.h>
+
 int utf8_encode(int32_t codepoint, char *buffer, size_t *size);
 
 size_t utf8_check_first(char byte);
