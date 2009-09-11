--- viewer/svutil.cpp.orig	2009-06-03 20:29:38.000000000 +0400
+++ viewer/svutil.cpp	2009-09-10 15:45:19.000000000 +0400
@@ -40,9 +40,13 @@
 #ifdef __linux__
 #include <sys/prctl.h>
 #endif
+#include <netinet/in.h>
 #endif
 
 #include <iostream>
+#include <cstring> 
+#include <cstdio> 
+#include <cstdlib>
 
 const int kBufferSize = 65536;
 const int kMaxMsgSize = 4096;
