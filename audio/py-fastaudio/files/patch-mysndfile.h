--- mysndfile.h.orig	2009-06-06 18:51:14.000000000 +0900
+++ mysndfile.h	2009-06-06 18:51:38.000000000 +0900
@@ -1,5 +1,5 @@
 #ifdef WIN32
 #include "sndfile-win32.h"
 #else
-#include "sndfile.h"
+#include "%%LOCALBASE%%/include/sndfile.h"
 #endif
