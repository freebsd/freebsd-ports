--- folly/FollyMemset.cpp.orig	2024-09-24 17:45:52 UTC
+++ folly/FollyMemset.cpp
@@ -16,7 +16,7 @@
 
 #include <cstring>
 
-#if !defined(__AVX2__) && !(defined(__linux__) && defined(__aarch64__))
+#if !defined(__AVX2__) && !((defined(__linux__) || defined(__FreeBSD__)) && defined(__aarch64__))
 
 namespace folly {
 
