$FreeBSD$

--- source/io.c.orig	1994-07-21 18:47:26.000000000 -0700
+++ source/io.c	2008-06-18 23:29:02.000000000 -0700
@@ -13,6 +13,11 @@
 
 #include "config.h"
 
+#ifdef __FreeBSD__
+#include <termios.h>
+#define USG
+#endif
+
 #ifdef HPUX
 #include <sys/bsdtty.h>
 #endif
@@ -201,7 +206,7 @@
 #if !defined(MAC) && !defined(MSDOS) && !defined(ATARI_ST) && !defined(VMS)
 #ifndef AMIGA
 #ifdef USG
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 static struct termios save_termio;
 #else
 static struct termio save_termio;
@@ -245,7 +250,9 @@
   struct ltchars lcbuf;
   struct tchars cbuf;
   int lbuf;
+#ifndef __FreeBSD__
   long time();
+#endif
 
   py.misc.male |= 2;
   (void) ioctl(0, TIOCGETP, (char *)&tbuf);
@@ -306,14 +313,16 @@
 #endif
 #else
 #if !defined(VMS) && !defined(MSDOS) && !defined(ATARI_ST)
-#ifndef AMIGA
+#if !defined(AMIGA) && !defined(__FreeBSD__)
   (void) ioctl(0, TCGETA, (char *)&save_termio);
+#else
+  (void) tcgetattr(0, &save_termio);
 #endif
 #endif
 #endif
 
   /* PC curses returns ERR */
-#if defined(USG) && !defined(PC_CURSES) && !defined(AMIGA)
+#if (defined(USG) && !defined(PC_CURSES) && !defined(AMIGA)) || defined(__FreeBSD__)
   if (initscr() == NULL)
 #else
   if (initscr() == ERR)
@@ -331,7 +340,7 @@
 #if defined(atarist) && defined(__GNUC__)
   (void) signal (SIGTSTP, (__Sigfunc)suspend);
 #else
-#ifdef  __386BSD__
+#if defined(__386BSD__) || defined(__FreeBSD__)
   (void) signal (SIGTSTP, (sig_t)suspend);
 #else
   (void) signal (SIGTSTP, suspend);
@@ -385,7 +394,7 @@
 #if !defined(MSDOS) && !defined(ATARI_ST) && !defined(VMS)
 #ifndef AMIGA
 #ifdef USG
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
   struct termios tbuf;
 #else
   struct termio tbuf;
@@ -420,7 +429,11 @@
 #else
 #if !defined(ATARI_ST) && !defined(VMS)
 #ifdef USG
+#ifdef __FreeBSD__
+  (void) tcgetattr(0, &tbuf);
+#else
   (void) ioctl(0, TCGETA, (char *)&tbuf);
+#endif
   /* disable all of the normal special control characters */
   tbuf.c_cc[VINTR] = (char)3; /* control-C */
   tbuf.c_cc[VQUIT] = (char)-1;
@@ -438,7 +451,11 @@
   tbuf.c_cc[VMIN] = 1;  /* Input should wait for at least 1 char */
   tbuf.c_cc[VTIME] = 0; /* no matter how long that takes. */
 
+#ifdef __FreeBSD__
+  (void) tcsetattr(0, TCSANOW, &tbuf);
+#else
   (void) ioctl(0, TCSETA, (char *)&tbuf);
+#endif
 #else
   /* disable all of the special characters except the suspend char, interrupt
      char, and the control flow start/stop characters */
@@ -552,9 +569,13 @@
 #ifdef USG
 #if !defined(MSDOS) && !defined(ATARI_ST) && !defined(VMS)
 #ifndef AMIGA
+#ifdef __FreeBSD__
+  (void) tcsetattr(0, TCSANOW, &save_termio);
+#else
   (void) ioctl(0, TCSETA, (char *)&save_termio);
 #endif
 #endif
+#endif
 #else
   (void) ioctl(0, TIOCSLTC, (char *)&save_special_chars);
   (void) ioctl(0, TIOCSETP, (char *)&save_ttyb);
@@ -646,7 +667,7 @@
 {
 #ifdef USG
 #if !defined(MSDOS) && !defined(ATARI_ST) && !defined(AMIGA)
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
   struct termios tbuf;
 #else
   struct termio tbuf;
@@ -683,8 +704,12 @@
 
 #ifdef USG
 #if !defined(MSDOS) && !defined(ATARI_ST) && !defined(AMIGA)
+#ifdef __FreeBSD__
+  (void) tcgetattr(0, &tbuf);
+#else
   (void) ioctl(0, TCGETA, (char *)&tbuf);
 #endif
+#endif
 #else
   (void) ioctl(0, TIOCGETP, (char *)&tbuf);
   (void) ioctl(0, TIOCGETC, (char *)&cbuf);
@@ -725,8 +750,12 @@
       default_signals();
 #ifdef USG
 #if !defined(MSDOS) && !defined(ATARI_ST) && !defined(AMIGA)
+#ifdef __FreeBSD__
+      (void) tcsetattr(0, TCSANOW, &save_termio);
+#else
       (void) ioctl(0, TCSETA, (char *)&save_termio);
 #endif
+#endif
 #else
       (void) ioctl(0, TIOCSLTC, (char *)&save_special_chars);
       (void) ioctl(0, TIOCSETP, (char *)&save_ttyb);
@@ -757,7 +786,7 @@
       msg_print("Fork failed. Try again.");
       return;
     }
-#if defined(USG) || defined(__386BSD__)
+#if defined(USG) || defined(__386BSD__) || defined(__FreeBSD__)
   (void) wait((int *) 0);
 #else
   (void) wait((union wait *) 0);
@@ -785,8 +814,12 @@
   /* have to disable ^Y for tunneling */
 #ifdef USG
 #if !defined(MSDOS) && !defined(ATARI_ST)
+#ifdef __FreeBSD__
+  (void) tcsetattr(0, TCSANOW, &tbuf);
+#else
   (void) ioctl(0, TCSETA, (char *)&tbuf);
 #endif
+#endif
 #else
   (void) ioctl(0, TIOCSLTC, (char *)&lcbuf);
   (void) ioctl(0, TIOCSETP, (char *)&tbuf);
