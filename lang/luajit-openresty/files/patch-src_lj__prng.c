--- src/lj_prng.c.orig	2020-10-02 19:16:39 UTC
+++ src/lj_prng.c
@@ -109,6 +109,7 @@ static PRGR libfunc_rgr;
 #include <sys/syscall.h>
 #else
 
+#ifndef LJ_TARGET_HAS_GETENTROPY
 #if LJ_TARGET_OSX
 #include <Availability.h>
 #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200 || \
@@ -117,6 +118,7 @@ static PRGR libfunc_rgr;
 #endif
 #elif LJ_TARGET_BSD || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
 #define LJ_TARGET_HAS_GETENTROPY	1
+#endif
 #endif
 
 #if LJ_TARGET_HAS_GETENTROPY
