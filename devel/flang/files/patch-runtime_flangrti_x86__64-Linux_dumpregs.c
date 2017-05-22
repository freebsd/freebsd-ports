--- runtime/flangrti/x86_64-Linux/dumpregs.c.orig	2017-05-17 00:40:01 UTC
+++ runtime/flangrti/x86_64-Linux/dumpregs.c
@@ -40,7 +40,7 @@
 #define RSP 15
 #define RIP 16
 
-#if defined(TARGET_OSX) || defined(TARGET_WIN)
+#if defined(TARGET_OSX) || defined(TARGET_WIN) || defined(__FreeBSD__)
 /* no gregs and/or ucontext defined in for OSX or Windows */
 void * 
 getRegs(void *u)
