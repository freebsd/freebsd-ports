--- jdk/src/solaris/native/sun/management/OperatingSystemImpl.c.orig	2015-12-10 18:40:39 UTC
+++ jdk/src/solaris/native/sun/management/OperatingSystemImpl.c
@@ -435,11 +435,6 @@ Java_sun_management_OperatingSystemImpl_
 }
 
 
-#ifdef _ALLBSD_SOURCE
-#define FD_DIR "/dev/fd"
-#else
-#define FD_DIR "/proc/self/fd"
-#endif
 
 JNIEXPORT jlong JNICALL
 Java_sun_management_OperatingSystemImpl_getOpenFileDescriptorCount
