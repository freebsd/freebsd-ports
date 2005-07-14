--- src/charsets/ucs4_dec.c.orig	Sat Jul  2 01:42:09 2005
+++ src/charsets/ucs4_dec.c	Thu Jul 14 17:49:12 2005
@@ -26,6 +26,10 @@
 #define MB_LEN_MAX 6
 #endif
 
+#ifndef UINT16_MAX
+#define UINT16_MAX USHRT_MAX
+#endif
+
 static
 size_t replace_char_escape (char **inbuf, size_t *inbytesleft,
                             char **outbuf, size_t *outbytesleft)
