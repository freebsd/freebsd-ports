--- uip/trmsbr.c.orig	1993-12-01 04:01:39 UTC
+++ uip/trmsbr.c
@@ -5,19 +5,8 @@ static char ident[] = "@(#)$Id: trmsbr.c
 
 #include "../h/mh.h"
 #include <stdio.h>
-#ifndef	SYS5
-#include <sgtty.h>
-#if	defined(ULTRIX) && !defined(BSD43)
-#undef	TIOCGWINSZ
-#endif
-#else	/* SYS5 */
-#include <sys/types.h>
-#include <termio.h>
-#ifndef	NOIOCTLH
 #include <sys/ioctl.h>
-#endif	/* NOIOCTLH */
-#undef	TIOCGWINSZ
-#endif	/* SYS5 */
+#include <termios.h>
 
 
 #if	BUFSIZ<2048
@@ -58,11 +47,7 @@ static  read_termcap () {
                    *term;
     char   *cp,
 	    myterm[TXTSIZ];
-#ifndef	SYS5
-    struct sgttyb   sg;
-#else	/* SYS5 */
-    struct termio   sg;
-#endif	/* SYS5 */
+    struct termios  sg;
     static int  inited = 0;
 
     if (inited++)
@@ -71,13 +56,7 @@ static  read_termcap () {
     if ((term = getenv ("TERM")) == NULL || tgetent (myterm, term) <= OK)
 	return;
 
-#ifndef	SYS5
-    ospeed = ioctl (fileno (stdout), TIOCGETP, (char *) &sg) != NOTOK
-		? sg.sg_ospeed : 0;
-#else	/* SYS5 */
-    ospeed = ioctl (fileno (stdout), TCGETA, &sg) != NOTOK
-		? sg.c_cflag & CBAUD : 0;
-#endif	/* SYS5 */
+    ospeed = tcgetattr (fileno (stdout), &sg) != NOTOK ? cfgetospeed(&sg) : 0;
 
     HC = tgetflag ("hc");
 
