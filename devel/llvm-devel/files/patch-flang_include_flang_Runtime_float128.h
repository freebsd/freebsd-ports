--- flang/include/flang/Runtime/float128.h.orig
+++ flang/include/flang/Runtime/float128.h
@@ -22,7 +22,7 @@
 
 #undef HAS_FLOAT128
 #if __x86_64__
-#if __GNUC__ >= 7 || __clang_major__ >= 7
+#if !defined(__FreeBSD__) && (__GNUC__ >= 7 || __clang_major__ >= 7)
 #define HAS_FLOAT128 1
 #endif
 #elif defined __PPC__ && __GNUC__ >= 8
