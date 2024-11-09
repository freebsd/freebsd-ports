--- src/lj_prng.c.orig	2024-10-02 11:59:42 UTC
+++ src/lj_prng.c
@@ -113,6 +113,7 @@ static PRGR libfunc_rgr;
 #include <sys/syscall.h>
 #else
 
+#ifndef LJ_TARGET_HAS_GETENTROPY
 #if LJ_TARGET_OSX && !LJ_TARGET_IOS
 /*
 ** In their infinite wisdom Apple decided to disallow getentropy() in the
@@ -124,6 +125,7 @@ static PRGR libfunc_rgr;
 #include <Availability.h>
 #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200
 #define LJ_TARGET_HAS_GETENTROPY	1
+#endif
 #endif
 #elif (LJ_TARGET_BSD && !defined(__NetBSD__)) || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN || LJ_TARGET_QNX
 #define LJ_TARGET_HAS_GETENTROPY	1
