--- ./src/Utility/ropeStuff.hh.orig	2014-09-03 02:27:15.000000000 +0200
+++ ./src/Utility/ropeStuff.hh	2014-09-03 02:28:58.000000000 +0200
@@ -25,6 +25,11 @@
 //
 #ifndef _ropeStuff_hh_
 #define _ropeStuff_hh_
+#include <cstddef>
+#ifdef _LIBCPP_VERSION
+#include <string>
+typedef std::string crope;
+#else
 #ifdef __GNUC__
   #if __GNUC__ < 3
     #include <rope.h>
@@ -50,3 +55,5 @@
 #include <rope>
 #endif
 #endif
+
+#endif
