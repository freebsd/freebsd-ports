$FreeBSD$

--- source/io.c.orig	Thu Jul 21 19:47:26 1994
+++ source/io.c	Fri Aug 15 07:42:02 2003
@@ -13,6 +13,11 @@
 
 #include "config.h"
 
+#ifdef __FreeBSD__
+#include <sys/ioctl_compat.h>
+#include <time.h>
+#endif
+
 #ifdef HPUX
 #include <sys/bsdtty.h>
 #endif
@@ -245,7 +250,9 @@
   struct ltchars lcbuf;
   struct tchars cbuf;
   int lbuf;
+#ifndef __FreeBSD__
   long time();
+#endif
 
   py.misc.male |= 2;
   (void) ioctl(0, TIOCGETP, (char *)&tbuf);
@@ -313,7 +320,7 @@
 #endif
 
   /* PC curses returns ERR */
-#if defined(USG) && !defined(PC_CURSES) && !defined(AMIGA)
+#if (defined(USG) && !defined(PC_CURSES) && !defined(AMIGA)) || defined(__FreeBSD__)
   if (initscr() == NULL)
 #else
   if (initscr() == ERR)
@@ -331,7 +338,7 @@
 #if defined(atarist) && defined(__GNUC__)
   (void) signal (SIGTSTP, (__Sigfunc)suspend);
 #else
-#ifdef  __386BSD__
+#if defined(__386BSD__) || defined(__FreeBSD__)
   (void) signal (SIGTSTP, (sig_t)suspend);
 #else
   (void) signal (SIGTSTP, suspend);
@@ -757,7 +764,7 @@
       msg_print("Fork failed. Try again.");
       return;
     }
-#if defined(USG) || defined(__386BSD__)
+#if defined(USG) || defined(__386BSD__) || defined(__FreeBSD__)
   (void) wait((int *) 0);
 #else
   (void) wait((union wait *) 0);
