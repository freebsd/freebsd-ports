--- kccommon.h.orig	2010-04-21 10:21:05.000000000 +0900
+++ kccommon.h	2010-04-23 01:29:11.788967538 +0900
@@ -84,9 +84,14 @@
 
 #else
 
+inline double log2(double num) {
+  return log(num) / M_LN2;
+}
+
 namespace std {
 using ::log2;
 using ::modfl;
+using ::snprintf;
 }
 
 #endif
