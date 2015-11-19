--- src/hugin1/icpfind/AutoCtrlPointCreator.cpp.orig	2015-07-18 02:44:00.000000000 +1000
+++ src/hugin1/icpfind/AutoCtrlPointCreator.cpp	2015-10-31 15:49:42.000000000 +1100
@@ -29,8 +29,10 @@
 
 #include <fstream>
 #ifdef __GNUC__
+#ifndef __FreeBSD__
 #include <ext/stdio_filebuf.h>
 #endif
+#endif
 
 #include "algorithms/optimizer/ImageGraph.h"
 
