--- src/grt/config/linux.c.orig	2015-05-27 18:49:40 UTC
+++ src/grt/config/linux.c
@@ -44,7 +44,7 @@
 #define EXTEND_STACK 1
 #define STACK_SIGNAL SIGSEGV
 #endif
-#ifdef __FreeBSD__
+#if defined (__FreeBSD__) || defined (__DragonFly__)
 /* If set, SIGSEGV is caught in order to automatically grow the stacks.  */
 #define EXTEND_STACK 1
 #define STACK_SIGNAL SIGSEGV
