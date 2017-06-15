--- aws-cpp-sdk-core/source/platform/linux-shared/Security.cpp.orig	2017-01-05 20:03:15.000000000 +0000
+++ aws-cpp-sdk-core/source/platform/linux-shared/Security.cpp	2017-01-07 15:07:42.656838000 +0000
@@ -25,7 +25,7 @@
 void SecureMemClear(unsigned char *data, size_t length)
 {
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
-    memset_s(data, length, 0, length);
+    memset(data, 0, length);
 #else
     memset(data, 0, length);
     asm volatile("" : "+m" (data));
