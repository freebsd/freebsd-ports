--- src/googletest.h.orig	2015-03-11 12:02:27.000000000 +0800
+++ src/googletest.h	2015-03-22 00:56:38.711647313 +0800
@@ -58,6 +58,7 @@
 
 #include "base/commandlineflags.h"
 
+using namespace gflags;
 using std::map;
 using std::string;
 using std::vector;
