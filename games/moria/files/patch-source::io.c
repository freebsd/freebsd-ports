$FreeBSD$

--- source/io.c	Thu Jul 21 19:47:26 1994
+++ source/io.c	Tue Aug  5 09:59:14 2003
@@ -13,6 +13,10 @@
 
 #include "config.h"
 
+#ifdef __FreeBSD__
+#include <sys/ioctl_compat.h>
+#endif
+
 #ifdef HPUX
 #include <sys/bsdtty.h>
 #endif
@@ -313,7 +317,7 @@
 #endif
 
   /* PC curses returns ERR */
-#if defined(USG) && !defined(PC_CURSES) && !defined(AMIGA)
+#if (defined(USG) && !defined(PC_CURSES) && !defined(AMIGA)) || defined(__FreeBSD__)
   if (initscr() == NULL)
 #else
   if (initscr() == ERR)
@@ -331,7 +335,7 @@
 #if defined(atarist) && defined(__GNUC__)
   (void) signal (SIGTSTP, (__Sigfunc)suspend);
 #else
-#ifdef  __386BSD__
+#if defined(__386BSD__) || defined(__FreeBSD__)
   (void) signal (SIGTSTP, (sig_t)suspend);
 #else
   (void) signal (SIGTSTP, suspend);
@@ -757,7 +761,7 @@
       msg_print("Fork failed. Try again.");
       return;
     }
-#if defined(USG) || defined(__386BSD__)
+#if defined(USG) || defined(__386BSD__) || defined(__FreeBSD__)
   (void) wait((int *) 0);
 #else
   (void) wait((union wait *) 0);
