--- jdk/src/solaris/native/sun/management/OperatingSystemImpl.c.orig	2017-09-06 22:12:44 UTC
+++ jdk/src/solaris/native/sun/management/OperatingSystemImpl.c
@@ -368,7 +368,9 @@ Java_sun_management_OperatingSystemImpl_
 #elif defined(__FreeBSD__)
     static const char *vm_stats[] = {
        "vm.stats.vm.v_free_count",
+#if __FreeBSD_version < 1200016
        "vm.stats.vm.v_cache_count",
+#endif
        /* "vm.stats.vm.v_inactive_count", */
        NULL
     };
@@ -435,11 +437,6 @@ Java_sun_management_OperatingSystemImpl_
 }
 
 
-#ifdef _ALLBSD_SOURCE
-#define FD_DIR "/dev/fd"
-#else
-#define FD_DIR "/proc/self/fd"
-#endif
 
 JNIEXPORT jlong JNICALL
 Java_sun_management_OperatingSystemImpl_getOpenFileDescriptorCount
