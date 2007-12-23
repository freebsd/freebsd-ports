--- ./stlport/stl/config/host.h.orig	2007-08-26 16:27:21.000000000 +0200
+++ ./stlport/stl/config/host.h	2007-11-19 00:02:25.000000000 +0100
@@ -72,10 +72,8 @@
  * _STLP_NATIVE_INCLUDE_PATH.
  * Hint: never install STLport in the directory that ends with "include"
  */
-/*
 #undef _STLP_NATIVE_INCLUDE_PATH
-#define _STLP_NATIVE_INCLUDE_PATH ../include
-*/
+#define _STLP_NATIVE_INCLUDE_PATH c++/__GNUC__.__GNUC_MINOR__
 /* same for C library headers like <cstring> */
 /*
 #undef _STLP_NATIVE_CPP_C_INCLUDE_PATH
