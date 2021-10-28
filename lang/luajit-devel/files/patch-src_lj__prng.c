--- src/lj_prng.c.orig	2021-10-27 20:58:55.107726000 -0400
+++ src/lj_prng.c	2021-10-27 21:00:37.533971000 -0400
@@ -109,6 +109,7 @@
 #include <sys/syscall.h>
 #else
 
+#ifndef LJ_TARGET_HAS_GETENTROPY
 #if LJ_TARGET_OSX && !LJ_TARGET_IOS
 /*
 ** In their infinite wisdom Apple decided to disallow getentropy() in the
@@ -120,6 +121,7 @@
 #include <Availability.h>
 #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200
 #define LJ_TARGET_HAS_GETENTROPY	1
+#endif
 #endif
 #endif
 #elif (LJ_TARGET_BSD && !defined(__NetBSD__)) || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
