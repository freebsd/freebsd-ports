--- runtime/flangrti/x86_64-Linux/dumpregs.c.orig	2019-10-09 20:28:35 UTC
+++ runtime/flangrti/x86_64-Linux/dumpregs.c
@@ -42,7 +42,7 @@
 #define RSP 15
 #define RIP 16
 
-#if defined(TARGET_OSX) || defined(TARGET_WIN)
+#if defined(TARGET_OSX) || defined(TARGET_WIN) || defined(__FreeBSD__)
 /* no gregs and/or ucontext defined in for OSX or Windows */
 void * 
 getRegs(void *u)
