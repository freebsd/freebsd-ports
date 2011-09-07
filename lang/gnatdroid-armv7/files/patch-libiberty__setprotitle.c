--- libiberty/setproctitle.c.orig	2011-01-29 07:11:03 +0100
+++ libiberty/setproctitle.c	2011-01-29 07:28:55 +0100
@@ -40,9 +40,11 @@
 void
 setproctitle (const char *name ATTRIBUTE_UNUSED, ...)
 {
+#ifndef __ANDROID__
 #ifdef PR_SET_NAME
   /* On Linux this sets the top visible "comm", but not necessarily
      the name visible in ps. */
   prctl (PR_SET_NAME, name);
 #endif
+#endif
 }
