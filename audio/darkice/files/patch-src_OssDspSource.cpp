--- src/OssDspSource.cpp.orig	Thu Feb 13 00:48:22 2003
+++ src/OssDspSource.cpp	Thu Jan  8 12:15:07 2004
@@ -86,6 +86,13 @@
 #error need sys/soundcard.h
 #endif
 
+#if !defined(AFMT_S16_NE)
+#if defined(BYTE_ORDER) && (BYTE_ORDER == BIG_ENDIAN)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
+#endif
 
 #include "Util.h"
 #include "Exception.h"
