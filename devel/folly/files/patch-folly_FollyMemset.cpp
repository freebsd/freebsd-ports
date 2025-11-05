--- folly/FollyMemset.cpp.orig	2025-11-02 05:43:14 UTC
+++ folly/FollyMemset.cpp
@@ -16,7 +16,7 @@
 
 #include <cstring> // @donotremove
 
-#if !defined(__AVX2__) && !(defined(__linux__) && defined(__aarch64__))
+#if !defined(__AVX2__) && !((defined(__linux__) || defined(__FreeBSD__)) && defined(__aarch64__))
 
 namespace folly {
 
