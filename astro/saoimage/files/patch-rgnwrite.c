--- rgnwrite.c.orig	Sun Jan 16 23:54:54 2000
+++ rgnwrite.c	Sun Jan 16 23:55:51 2000
@@ -183,7 +183,7 @@
 #ifdef LONG64
   int time();
 #else
-#ifndef VMS
+#if !defined(VMS) && !defined(__FreeBSD__)
   long time();
 #else
   time_t time();
