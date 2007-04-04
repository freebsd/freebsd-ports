--- mysndfile.h.orig	Tue Jun 15 13:37:39 2004
+++ mysndfile.h	Sat Mar  3 11:53:57 2007
@@ -1,5 +1,5 @@
 #ifdef WIN32
 #include "sndfile-win32.h"
 #else
-#include "sndfile.h"
+#include "/usr/local/include/sndfile.h"
 #endif
