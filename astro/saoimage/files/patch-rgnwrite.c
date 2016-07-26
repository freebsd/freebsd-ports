--- rgnwrite.c.orig	1995-09-08 22:29:19 UTC
+++ rgnwrite.c
@@ -183,7 +183,7 @@ static void set_time_string ( time_strin
 #ifdef LONG64
   int time();
 #else
-#ifndef VMS
+#if !defined(VMS) && !defined(__FreeBSD__)
   long time();
 #else
   time_t time();
