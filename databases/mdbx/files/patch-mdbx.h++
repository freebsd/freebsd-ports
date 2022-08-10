--- mdbx.h++.orig	2022-08-02 10:17:33 UTC
+++ mdbx.h++
@@ -23,6 +23,8 @@
 
 #pragma once
 
+#define _LIBCPP_NO_EXPERIMENTAL_DEPRECATION_WARNING_FILESYSTEM
+
 /* Workaround for modern libstdc++ with CLANG < 4.x */
 #if defined(__SIZEOF_INT128__) && !defined(__GLIBCXX_TYPE_INT_N_0) &&          \
     defined(__clang__) && __clang_major__ < 4
