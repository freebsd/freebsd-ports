--- src/utf8.c.orig	Wed Jun 14 15:33:19 2006
+++ src/utf8.c	Wed Dec 13 08:40:35 2006
@@ -23,7 +23,7 @@
  */
 
 /* UTF8 encoding/decoding
- * $Id: utf8.c,v 1.3 2006/06/14 23:33:19 castaglia Exp $
+ * $Id: utf8.c,v 1.4 2006/12/13 17:40:35 castaglia Exp $
  */
 
 #include "conf.h"
@@ -38,12 +38,13 @@
 # include <langinfo.h>
 #endif
 
+#ifdef HAVE_ICONV_H
 static iconv_t decode_conv = (iconv_t) -1;
 static iconv_t encode_conv = (iconv_t) -1;
 
 static int utf8_convert(iconv_t conv, char *inbuf, size_t *inbuflen,
     char *outbuf, size_t *outbuflen) {
-#ifdef HAVE_ICONV
+# ifdef HAVE_ICONV
   char *start = inbuf;
 
   while (inbuflen > 0) {
@@ -61,14 +62,14 @@
     break;
   }
   return 0;
-#else
+# else
   errno = ENOSYS;
   return -1;
-#endif /* HAVE_ICONV */
+# endif /* HAVE_ICONV */
 }
 
 int utf8_free(void) {
-#ifdef HAVE_ICONV
+# ifdef HAVE_ICONV
   int res;
 
   /* Close the iconv handles. */
@@ -81,10 +82,10 @@
     return -1;
 
   return 0;
-#else
+# else
   errno = ENOSYS;
   return -1;
-#endif
+# endif
 }
 
 int utf8_init(void) {
@@ -111,7 +112,7 @@
     "conversion");
 #endif /* HAVE_NL_LANGINFO */
 
-#ifdef HAVE_ICONV
+# ifdef HAVE_ICONV
   /* Get the iconv handles. */
   encode_conv = iconv_open(local_charset, "UTF-8");
   if (encode_conv == (iconv_t) -1)
@@ -122,13 +123,15 @@
     return -1;
 
   return 0;
-#else
+# else
   errno = ENOSYS;
   return -1;
-#endif /* HAVE_ICONV */
+# endif /* HAVE_ICONV */
 }
+#endif /* !HAVE_ICONV_H */
 
 char *pr_utf8_decode(pool *p, const char *in, size_t inlen, size_t *outlen) {
+#ifdef HAVE_ICONV_H
   size_t inbuflen, outbuflen;
   char *inbuf, outbuf[PR_TUNABLE_PATH_MAX*2], *res = NULL;
 
@@ -156,9 +159,14 @@
   memcpy(res, outbuf, *outlen);
 
   return res;
+#else
+  pr_trace_msg("utf8", 1, "missing iconv support, no UTF8 decoding possible");
+  return pstrdup(p, in);
+#endif /* !HAVE_ICONV_H */
 }
 
 char *pr_utf8_encode(pool *p, const char *in, size_t inlen, size_t *outlen) {
+#ifdef HAVE_ICONV_H
   size_t inbuflen, outbuflen;
   char *inbuf, outbuf[PR_TUNABLE_PATH_MAX*2], *res;
 
@@ -186,6 +194,10 @@
   memcpy(res, outbuf, *outlen);
 
   return res;
+#else
+  pr_trace_msg("utf8", 1, "missing iconv support, no UTF8 encoding possible");
+  return pstrdup(p, in);
+#endif /* !HAVE_ICONV_H */
 }
 
 #endif /* PR_USE_NLS */
