--- src/OssDspSource.cpp.orig	Sun Jan 26 18:48:57 2003
+++ src/OssDspSource.cpp	Mon Feb 10 21:40:43 2003
@@ -86,6 +86,13 @@
 #error need sys/soundcard.h
 #endif
 
+#if defined(__FreeBSD__)
+#if defined(__sparc__) || defined(__powerpc__)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
+#endif
 
 #include "Util.h"
 #include "Exception.h"
