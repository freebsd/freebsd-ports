--- aws-cpp-sdk-core/source/platform/linux-shared/Security.cpp.orig	2017-01-03 09:10:58.573735000 +0000
+++ aws-cpp-sdk-core/source/platform/linux-shared/Security.cpp	2017-01-03 09:11:08.709468000 +0000
@@ -24,7 +24,7 @@
 
 void SecureMemClear(unsigned char *data, size_t length)
 {
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
     memset_s(data, length, 0, length);
 #else
     memset(data, 0, length);
