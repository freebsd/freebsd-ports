--- src/logging_unittest.cc.orig	2015-03-11 12:02:27.000000000 +0800
+++ src/logging_unittest.cc	2015-03-22 00:54:39.798664493 +0800
@@ -78,6 +78,7 @@
 #endif
 
 using namespace std;
+using namespace gflags;
 using namespace GOOGLE_NAMESPACE;
 
 // Some non-advertised functions that we want to test or use.
