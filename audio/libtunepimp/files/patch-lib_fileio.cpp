--- lib/fileio.cpp.orig	2006-11-18 11:52:33.000000000 +0100
+++ lib/fileio.cpp	2010-06-20 18:37:34.000000000 +0200
@@ -28,6 +28,8 @@
 #include <assert.h>
 #include <errno.h>
+#include <stdlib.h>
 #include <string>
+#include <string.h>
 #ifndef WIN32
 #include <unistd.h>
 #endif
