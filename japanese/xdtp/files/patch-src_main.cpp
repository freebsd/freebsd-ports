--- src/main.cpp.orig	2013-10-06 03:56:39.000000000 +0900
+++ src/main.cpp	2013-10-06 03:56:58.000000000 +0900
@@ -36,6 +36,8 @@
 #include "xdtp.h"
 #include "XDTPTransform.h"
 
+#include <getopt.h>
+
 using namespace XDTP;
 
 static void initialize_locale();
