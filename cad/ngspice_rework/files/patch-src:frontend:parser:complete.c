--- src/frontend/parser/complete.c.orig	Mon Dec 10 20:21:11 2001
+++ src/frontend/parser/complete.c	Wed Jan  2 13:57:11 2002
@@ -410,11 +410,6 @@
 #  else
 #    ifdef HAVE_TERMIOS_H
 
-#      ifdef __NetBSD__
-#        define TCGETS
-#        define TCSETS
-#      endif
-
 #      define TERM_GET TCGETS
 #      define TERM_SET TCSETS
     static struct termios sbuf;
@@ -423,7 +418,7 @@
 #    endif
 #  endif
 
-#  if defined(TERM_GET) || defined(__NetBSD__)
+#  ifdef TERM_GET
     static bool ison = FALSE;
 
     if (cp_nocc || !cp_interactive || (ison == on))
@@ -431,7 +426,7 @@
     ison = on;
 
     if (ison == TRUE) {
-#ifdef __NetBSD__
+#if HAVE_TCGETATTR
 	tcgetattr(fileno(cp_in),&OS_Buf);
 #else
 	(void) ioctl(fileno(cp_in), TERM_GET, (char *) &OS_Buf);
@@ -440,13 +435,13 @@
 	sbuf.c_cc[VEOF] = 0;
 	sbuf.c_cc[VEOL] = ESCAPE;
 	sbuf.c_cc[VEOL2] = CNTRL_D;
-#ifdef __NetBSD__
+#if HAVE_TCSETATTR
 	tcsetattr(fileno(cp_in),TCSANOW,&sbuf);
 #else
 	(void) ioctl(fileno(cp_in), TERM_SET, (char *) &sbuf);
 #endif
     } else {
-#ifdef __NetBSD__
+#if HAVE_TCSETATTR
 	tcsetattr(fileno(cp_in),TCSANOW,&OS_Buf);
 #else
 	(void) ioctl(fileno(cp_in), TERM_SET, (char *) &OS_Buf);
