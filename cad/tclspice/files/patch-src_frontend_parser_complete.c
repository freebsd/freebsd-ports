--- ./src/frontend/parser/complete.c.orig	Sat Jun 24 01:40:09 2006
+++ ./src/frontend/parser/complete.c	Sat Jun 24 01:40:17 2006
@@ -415,7 +415,7 @@
 #  else
 #    ifdef HAVE_TERMIOS_H
 
-#      if defined(__NetBSD__) || defined(__APPLE_CC__)
+#      if defined(__NetBSD__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 #        define TCGETS
 #        define TCSETS
 #      endif
@@ -428,7 +428,7 @@
 #    endif
 #  endif
 
-#  if defined(TERM_GET) || defined(__NetBSD__) || defined(__APPLE_CC__)
+#  if defined(TERM_GET) || defined(__NetBSD__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
     static bool ison = FALSE;
 
     if (cp_nocc || !cp_interactive || (ison == on))
@@ -436,7 +436,7 @@
     ison = on;
 
     if (ison == TRUE) {
-#if defined(__NetBSD__) || defined(__APPLE_CC__)
+#if defined(__NetBSD__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 	tcgetattr(fileno(cp_in),&OS_Buf);
 #else
 	(void) ioctl(fileno(cp_in), TERM_GET, (char *) &OS_Buf);
@@ -445,13 +445,13 @@
 	sbuf.c_cc[VEOF] = 0;
 	sbuf.c_cc[VEOL] = ESCAPE;
 	sbuf.c_cc[VEOL2] = CNTRL_D;
-#if defined(__NetBSD__) || defined(__APPLE_CC__)
+#if defined(__NetBSD__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 	tcsetattr(fileno(cp_in),TCSANOW,&sbuf);
 #else
 	(void) ioctl(fileno(cp_in), TERM_SET, (char *) &sbuf);
 #endif
     } else {
-#if defined(__NetBSD__) || defined(__APPLE_CC__)
+#if defined(__NetBSD__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 	tcsetattr(fileno(cp_in),TCSANOW,&OS_Buf);
 #else
 	(void) ioctl(fileno(cp_in), TERM_SET, (char *) &OS_Buf);
