--- aws-cpp-sdk-core/source/platform/linux-shared/Security.cpp.orig	2018-09-13 20:09:34 UTC
+++ aws-cpp-sdk-core/source/platform/linux-shared/Security.cpp
@@ -25,7 +25,7 @@ namespace Security
 void SecureMemClear(unsigned char *data, size_t length)
 {
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
-    memset_s(data, length, 0, length);
+    memset(data, 0, length);
 #else
     memset(data, 0, length);
     asm volatile("" : "+m" (data));
