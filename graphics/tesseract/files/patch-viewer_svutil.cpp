--- viewer/svutil.cpp.orig	2008-04-22 00:07:25.000000000 +0000
+++ viewer/svutil.cpp	2009-04-14 12:13:10.000000000 +0000
@@ -34,10 +34,14 @@
 #ifdef __linux__
 #include <sys/prctl.h>
 #endif
+#include <netinet/in.h>
 #endif
 
 #include <iostream>
 #include <string>
+#include <cstring>
+#include <cstdio>
+#include <cstdlib>
 
 const int kBufferSize = 65536;
 const int kMaxMsgSize = 4096;
