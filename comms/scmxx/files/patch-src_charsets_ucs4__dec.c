
$FreeBSD$

--- src/charsets/ucs4_dec.c.orig
+++ src/charsets/ucs4_dec.c
@@ -21,6 +21,12 @@
 #include <errno.h>
 #include <iconv.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version < 500000
+#include <limits.h>
+#define UINT16_MAX USHRT_MAX
+#endif
+
 size_t replace_char_escape (char **inbuf, size_t *inbytesleft,
                             char **outbuf, size_t *outbytesleft)
 {
