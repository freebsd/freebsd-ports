--- src/lj_prng.c.orig	2021-11-17 04:07:33 UTC
+++ src/lj_prng.c
@@ -109,6 +109,7 @@ static PRGR libfunc_rgr;
 #include <sys/syscall.h>
 #else
 
+#ifndef LJ_TARGET_HAS_GETENTROPY
 #if LJ_TARGET_OSX && !LJ_TARGET_IOS
 /*
 ** In their infinite wisdom Apple decided to disallow getentropy() in the
@@ -123,6 +124,7 @@ static PRGR libfunc_rgr;
 #endif
 #elif (LJ_TARGET_BSD && !defined(__NetBSD__)) || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
 #define LJ_TARGET_HAS_GETENTROPY	1
+#endif
 #endif
 
 #if LJ_TARGET_HAS_GETENTROPY
