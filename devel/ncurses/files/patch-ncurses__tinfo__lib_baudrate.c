--- ./ncurses/tinfo/lib_baudrate.c.orig	2002-01-20 07:07:53.000000000 +0800
+++ ./ncurses/tinfo/lib_baudrate.c	2008-06-11 21:12:53.000000000 +0800
@@ -39,6 +39,9 @@
 #include <curses.priv.h>
 #include <term.h>		/* cur_term, pad_char */
 #include <termcap.h>		/* ospeed */
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 
 /*
  * These systems use similar header files, which define B1200 as 1200, etc.,
@@ -46,7 +49,7 @@
  * of the indices up to B115200 fit nicely in a 'short', allowing us to retain
  * ospeed's type for compatibility.
  */
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 700000)) || defined(__NetBSD__) || defined(__OpenBSD__)
 #undef B0
 #undef B50
 #undef B75
