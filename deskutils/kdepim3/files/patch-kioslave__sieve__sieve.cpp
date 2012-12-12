--- kioslaves/sieve/sieve.cpp.orig	2008-08-19 20:15:48.000000000 +0200
+++ kioslaves/sieve/sieve.cpp	2012-12-12 10:22:13.000000000 +0100
@@ -28,6 +28,7 @@
 # include <config.h>
 #endif
 
+#include <sys/types.h>
 extern "C" {
 #include <sasl/sasl.h>
 }
