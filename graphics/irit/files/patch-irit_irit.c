--- irit/irit.c.orig	Mon Feb  2 10:51:52 2004
+++ irit/irit.c	Mon Feb  2 11:00:42 2004
@@ -40,8 +40,13 @@
 #include "intr_gr.h"
 #endif /* DJGCC */
 #ifdef __UNIX__
+#if defined (__FreeBSD__)
+#include <term.h>
+STATIC_DATA struct termios GlblOrigTermio;
+#else
 #include <termio.h>
 STATIC_DATA struct termio GlblOrigTermio;
+#endif /* !__FreeBSD__ */
 #endif /* __UNIX__ */
 
 #ifdef NO_CONCAT_STR
@@ -285,20 +290,33 @@
 
 #   ifdef __UNIX__
     {
+#if defined (__FreeBSD__)
+	struct termios Termio;
+#else
 	struct termio Termio;
+#endif /* !__FreeBSD__ */
 
 	/* We read stdin on a char by char basis with a 0.1 second timer so  */
 	/* we could simultaneously handle other requests (for example, from  */
 	/* display devices).						     */
+#if defined (__FreeBSD__)
+	tcgetattr(0, &GlblOrigTermio);
+	tcgetattr(0, &Termio);
+#else
 	ioctl(0, TCGETA, &GlblOrigTermio);
 	ioctl(0, TCGETA, &Termio);
+#endif /* !__FreeBSD__ */
 	Termio.c_lflag &= ~ICANON;	     /* Clear the canonical editing. */
 	Termio.c_cc[VEOF] = 0;    /* MIN = 0, no minimal length to wait for. */
 	Termio.c_cc[VEOL] = 1;    /* TIME - 1 tenth of a second as time out. */
 #       ifdef VSUSP
 	    Termio.c_cc[VSUSP] = 0;		   /* Disable ^Z suspension. */
 #       endif /* VSUSP */
+#if defined (__FreeBSD__)
+	tcsetattr(0, TCSANOW, &Termio);
+#else
 	ioctl(0, TCSETA, &Termio);
+#endif /* !__FreeBSD__ */
     }
 #   endif /* __UNIX__ */
 
@@ -819,7 +837,11 @@
 	fclose(GlblLogFile);		      /* Close log file if was open. */
 
 #   ifdef __UNIX__    
+#if defined (__FreeBSD__)
+	tcsetattr(0, TCSANOW, &GlblOrigTermio);
+#else
 	ioctl(0, TCSETA, &GlblOrigTermio);
+#endif /* !__FreeBSD__ */
 #   endif /* __UNIX__ */
 
 #   ifdef __WINNT__
