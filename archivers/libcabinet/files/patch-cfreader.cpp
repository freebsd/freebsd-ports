--- cfreader.cpp.orig	Tue Aug 19 18:28:46 2003
+++ cfreader.cpp	Tue Aug 19 18:29:10 2003
@@ -31,6 +31,8 @@
 #include "cfheader.h"
 #include "cfreader.h"
 
+using std::ios;
+
 ////////////////////////////////////////****************************************
 
 int cabinet_reader::open(const char* fname)
