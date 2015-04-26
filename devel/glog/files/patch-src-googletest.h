--- src/googletest.h.orig	2015-03-11 04:02:27 UTC
+++ src/googletest.h
@@ -58,6 +58,7 @@
 
 #include "base/commandlineflags.h"
 
+using namespace gflags;
 using std::map;
 using std::string;
 using std::vector;
