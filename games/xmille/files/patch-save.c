--- save.c.orig	Thu Apr  2 05:56:45 1992
+++ save.c	Fri Jun 15 02:20:34 2007
@@ -1,43 +1,46 @@
 #include	"mille.h"
 #include	<sys/types.h>
 #include	<sys/stat.h>
-#include	<sys/time.h>
+#include	<time.h>
+#include	<errno.h>
+#include	<string.h>
+#include	<stdlib.h>
 # ifdef	attron
 #	include	<term.h>
 #	define	_tty	cur_term->Nttyb
-# endif	attron
+# endif	
 
 /*
  * @(#)save.c	1.4 (Berkeley) 7/3/83
  */
 
 typedef	struct stat	Stat;
-typedef	struct tm	Time;
 
 char	*ctime();
 
 int	read(), write();
+char*   GetpromptedInput( char* );
 
 /*
  *	This routine saves the current game for use at a later date
  */
 extern int	errno;
-extern char	*sys_errlist[];
+/* extern char	*sys_errlist[]; */
 
 save() {
 
 	reg char	*sp;
 	reg int		outf;
-	reg Time	*tp;
+	reg time_t	*tp;
 	char		buf[80];
-	Time		tme;
+	time_t		tme;
 	Stat		junk;
 
 	tp = &tme;
 	if (Fromfile && getyn("Same file? "))
-		strcpy(buf, Fromfile);
+	        strncpy(buf, Fromfile,sizeof(buf));
 	else {
-		strcpy (buf, GetpromptedInput ("file: "));
+	        strncpy (buf, GetpromptedInput ("file: "), sizeof(buf));
 		sp = buf + strlen (buf);
 	}
 
@@ -50,12 +53,13 @@
 		return FALSE;
 
 	if ((outf = creat(buf, 0644)) < 0) {
-		error(sys_errlist[errno]);
+		/* error(sys_errlist[errno]); */
+		strerror(errno);
 		return FALSE;
 	}
 	Error (buf);
 	time(tp);			/* get current time		*/
-	strcpy(buf, ctime(tp));
+	strncpy(buf, ctime(tp), sizeof(buf));
 	for (sp = buf; *sp != '\n'; sp++)
 		continue;
 	*sp = '\0';
@@ -87,7 +91,7 @@
 	}
 	varpush(inf, read);
 	close(inf);
-	strcpy(buf, ctime(&sbuf.st_mtime));
+	strncpy(buf, ctime(&sbuf.st_mtime),sizeof(buf));
 	for (sp = buf; *sp != '\n'; sp++)
 		continue;
 	*sp = '\0';
