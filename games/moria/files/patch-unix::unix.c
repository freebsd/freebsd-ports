$FreeBSD$

--- unix/unix.c.orig	Tue Aug 12 10:36:13 2003
+++ unix/unix.c	Tue Aug 12 10:38:47 2003
@@ -14,6 +14,10 @@
 /* defines TRUE and FALSE */
 #include <curses.h>
 
+#ifdef __FreeBSD__
+#include <unistd.h>
+#endif
+
 #include "config.h"
 #include "constant.h"
 #include "types.h"
@@ -276,7 +280,9 @@
 void user_name(buf)
 char *buf;
 {
+#ifndef __FreeBSD__
   extern char *getlogin();
+#endif
   struct passwd *pwline;
   register char *p;
 
