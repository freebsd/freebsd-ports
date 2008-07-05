--- uip/prompter.c
+++ uip/prompter.c
@@ -6,15 +6,7 @@
 #include "../h/mh.h"
 #include <stdio.h>
 #include <errno.h>
-#ifndef	SYS5
-#include <sgtty.h>
-#else	/* SYS5 */
-#include <sys/types.h>
-#include <termio.h>
-#ifndef	NOIOCTLH
-#include <sys/ioctl.h>
-#endif	/* NOIOCTLH */
-#endif	/* SYS5 */
+#include <termios.h>
 #if defined(BSD42) || defined(SVR4)
 #include <setjmp.h>
 #endif	/* BSD42 || SVR4 */
@@ -71,19 +63,10 @@
 extern int  errno;
 
 
-#ifndef	SYS5
-#define	ERASE	sg.sg_erase
-#define	KILL	sg.sg_kill
-static struct sgttyb    sg;
-
-#define	INTR	tc.t_intrc
-static struct tchars    tc;
-#else	/* SYS5 */
 #define	ERASE	sg.c_cc[VERASE]
 #define	KILL	sg.c_cc[VKILL]
 #define	INTR	sg.c_cc[VINTR]
-static struct termio    sg;
-#endif	/* SYS5 */
+static struct termios    sg;
 
 
 static TYPESIG	intrser ();
@@ -209,29 +192,14 @@
     (void) chmod (tmpfil, 0600);
 
     if (killp || erasep) {
-#ifndef	SYS5
-	int    serase,
-	       skill;
-#else	/* SYS5 */
-	char   serase,
-	       skill;
-#endif	/* SYS5 */
-
-#ifndef	SYS5
-	(void) ioctl (0, TIOCGETP, (char *) &sg);
-	(void) ioctl (0, TIOCGETC, (char *) &tc);
-#else	/* SYS5 */
-	(void) ioctl(0, TCGETA, &sg);
-#endif	/* SYS5 */
+	cc_t serase, skill;
+
+	(void) tcgetattr(0, &sg);
 	skill = KILL;
 	serase = ERASE;
 	KILL = killp ? chrcnv (killp) : skill;
 	ERASE = erasep ? chrcnv (erasep) : serase;
-#ifndef	SYS5
-	(void) ioctl (0, TIOCSETN, (char *) &sg);
-#else	/* SYS5 */
-	(void) ioctl(0, TCSETAW, &sg);
-#endif	/* SYS5 */
+	(void) tcsetattr(0, TCSADRAIN, &sg);
 
 	chrdsp ("erase", ERASE);
 	chrdsp (", kill", KILL);
@@ -273,11 +241,7 @@
 		    if (i == -1) {
 abort: ;
 			if (killp || erasep)
-#ifndef	SYS5
-			    (void) ioctl (0, TIOCSETN, (char *) &sg);
-#else	/* SYS5 */
-			    (void) ioctl (0, TCSETA, &sg);
-#endif	/* SYS5 */
+			    (void) tcsetattr (0, TCSANOW, &sg);
 			(void) unlink (tmpfil);
 			done (1);
 		    }
@@ -365,11 +329,7 @@
 /*  */
 
     if (killp || erasep)
-#ifndef	SYS5
-	(void) ioctl (0, TIOCSETN, (char *) &sg);
-#else	/* SYS5 */
-	(void) ioctl (0, TCSETAW, &sg);
-#endif	/* SYS5 */
+	(void) tcsetattr (0, TCSANOW, &sg);
 
     if ((fdi = open (tmpfil, 0)) == NOTOK)
 	adios (tmpfil, "unable to re-open");
