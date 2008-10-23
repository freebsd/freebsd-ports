--- source/main/cTaskLib.cc.orig	2007-09-05 23:53:07.000000000 +0400
+++ source/main/cTaskLib.cc	2008-10-13 19:32:10.000000000 +0400
@@ -41,8 +41,8 @@
 // Various workarounds for Visual Studio shortcomings
 #if AVIDA_PLATFORM(WINDOWS)
 # define llabs(x) _abs64(x)
-# define log2(x) (log(x)/log(2.0))
 #endif
+# define log2(x) (log(x)/log(2.0))
 
 static const double dCastPrecision = 100000.0;
 
