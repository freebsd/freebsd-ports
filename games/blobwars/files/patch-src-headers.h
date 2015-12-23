--- src/headers.h.orig	2015-11-21 23:18:19.000000000 +0100
+++ src/headers.h	2015-12-01 17:38:16.209096616 +0100
@@ -56,11 +56,6 @@
 #define textdomain(x) while(false)
 #endif
 
-#if !defined(OpenBSD) && !defined(FreeBSD) && !defined(__APPLE__)
-static inline void strlcat(char *dest, const char *src, size_t n) { strncat(dest, src, n - 1); }
-static inline void strlcpy(char *dest, const char *src, size_t n) { strncpy(dest, src, n); dest[n - 1] = 0; }
-#endif
-
 #include "defs.h"
 
 #include "CMath.h"
