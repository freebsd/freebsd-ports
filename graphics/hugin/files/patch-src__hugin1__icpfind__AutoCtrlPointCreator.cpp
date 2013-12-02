--- src/hugin1/icpfind/AutoCtrlPointCreator.cpp.orig	2013-12-01 19:41:03.000000000 +0200
+++ src/hugin1/icpfind/AutoCtrlPointCreator.cpp	2013-12-01 19:41:25.000000000 +0200
@@ -28,7 +28,7 @@
 #include "panoinc.h"
 
 #include <fstream>
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(_LIBCPP_VERSION)
 #include <ext/stdio_filebuf.h>
 #endif
 
