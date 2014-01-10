--- libraries/base/cbits/iconv.c.orig	2013-04-18 23:30:14.000000000 +0200
+++ libraries/base/cbits/iconv.c	2013-12-15 22:08:45.995398103 +0100
@@ -1,12 +1,28 @@
 #ifndef __MINGW32__
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
 #include <stdlib.h>
 #include <iconv.h>
 
+#if __FreeBSD_version >= 1000502
+iconv_t	__bsd_iconv_open(const char *, const char *);
+size_t	__bsd_iconv(iconv_t, const char ** __restrict,
+	      size_t * __restrict, char ** __restrict,
+	      size_t * __restrict);
+int	__bsd_iconv_close(iconv_t);
+#endif
+
 iconv_t hs_iconv_open(const char* tocode,
 		      const char* fromcode)
 {
+#if __FreeBSD_version >= 1000502
+	return __bsd_iconv_open(tocode, fromcode);
+#else
 	return iconv_open(tocode, fromcode);
+#endif
 }
 
 size_t hs_iconv(iconv_t cd,
@@ -15,11 +31,19 @@
 {
     // (void*) cast avoids a warning.  Some iconvs use (const
     // char**inbuf), other use (char **inbuf).
+#if __FreeBSD_version >= 1000502
+    return __bsd_iconv(cd, (void*)inbuf, inbytesleft, outbuf, outbytesleft);
+#else
     return iconv(cd, (void*)inbuf, inbytesleft, outbuf, outbytesleft);
+#endif
 }
 
 int hs_iconv_close(iconv_t cd) {
+#if __FreeBSD_version >= 1000502
+	return __bsd_iconv_close(cd);
+#else
 	return iconv_close(cd);
+#endif
 }
 
 #endif
