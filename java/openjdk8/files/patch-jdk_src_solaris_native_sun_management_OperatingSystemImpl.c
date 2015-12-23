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
@@ -500,6 +495,8 @@ Java_sun_management_OperatingSystemImpl_
 #define FD_DIR aix_fd_dir
     char aix_fd_dir[32];     /* the pid has at most 19 digits */
     snprintf(aix_fd_dir, 32, "/proc/%d/fd", getpid());
+#elif defined(_ALLBSD_SOURCE)
+#define FD_DIR "/dev/fd"
 #else
 #define FD_DIR "/proc/self/fd"
 #endif
