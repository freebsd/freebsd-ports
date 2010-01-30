--- src/utf.h.orig	2010-01-30 20:53:52.000000000 +0800
+++ src/utf.h	2010-01-30 20:54:05.000000000 +0800
@@ -8,6 +8,8 @@
 #ifndef UTF_H
 #define UTF_H
 
+#include <sys/types.h>
+
 int utf8_encode(int codepoint, char *buffer, int *size);
 
 int utf8_check_first(char byte);
