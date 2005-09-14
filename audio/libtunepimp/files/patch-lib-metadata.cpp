--- lib/metadata.cpp.orig	Wed Nov 10 17:37:26 2004
+++ lib/metadata.cpp	Wed Sep 14 17:25:59 2005
@@ -34,6 +34,14 @@
    #include "astrcmp.h"
 }
 
+#ifndef min
+#define min(a,b) ((a) < (b) ? (a) : (b))
+#endif
+
+#ifndef max
+#define max(a,b) ((a) > (b) ? (a) : (b))
+#endif
+
 const int numAlbumTypeStrings = 11;
 const char *albumTypeStrings[] =
 {
