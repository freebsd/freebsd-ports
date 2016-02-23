--- soundcard/modem.h.orig	2015-05-04 17:48:03 UTC
+++ soundcard/modem.h
@@ -79,11 +79,15 @@ typedef unsigned long long /* deduced */
 
 /* ---------------------------------------------------------------------- */
 
+#if __clang__ > 0
+#define only_inline inline
+#else
 #if __GNUC__ < 5
 #define only_inline extern inline
 #else
 #define only_inline inline
 #endif
+#endif
 
 struct modemchannel;
 
