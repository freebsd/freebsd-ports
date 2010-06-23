--- uip/rcvtty.c.orig	2001-04-05 01:05:17.000000000 +0900
+++ uip/rcvtty.c	2010-04-12 17:36:19.000000000 +0900
@@ -12,7 +12,11 @@
 #include "../zotnet/tws.h"
 #include <signal.h>
 #include <sys/stat.h>
+#include <sys/param.h>
 #ifndef	TTYD
+#if __FreeBSD_version > 900007
+#include <utmpx.h>
+#else /* __FreeBSD_version > 900007 */
 #include <utmp.h>
 #ifndef UTMP_FILENAME
 #ifdef UTMP_FILE
@@ -25,6 +29,7 @@
 #endif
 #endif
 #endif	/* UTMP_FILENAME */
+#endif /* __FreeBSD_version > 900007 */
 #endif	/* not TTYD */
 #ifdef LOCALE
 #include	<locale.h>
@@ -110,8 +115,12 @@
 	   *vec[MAXARGS];
 #ifndef	TTYD
     char    tty[BUFSIZ];
+#if __FreeBSD_version > 900007
+    struct utmpx *ut;
+#else /* __FreeBSD_version > 900007 */
     struct utmp ut;
     register FILE  *uf;
+#endif /* __FreeBSD_version > 900007 */
 #endif	/* not TTYD */
 
 #ifdef BSD43
@@ -200,6 +209,13 @@
 
     user = getusr ();
 #ifndef	TTYD
+#if __FreeBSD_version > 900007
+    ut = getutxuser(user);
+    if (ut != NULL) {
+	(void) strncpy (tty, ut->ut_line, sizeof ut->ut_line);
+	alert (tty, md);
+    }
+#else /* __FreeBSD_version > 900007 */
     if ((uf = fopen (UTMP_FILENAME, "r")) == NULL)
 	exit (RCV_MBX);
     while (fread ((char *) &ut, sizeof ut, 1, uf) == 1)
@@ -212,6 +228,7 @@
 	    alert (tty, md);
 	}
     (void) fclose (uf);
+#endif /* __FreeBSD_version > 900007 */
 #else	/* TTYD */
     alert (user, md);
 #endif	/* TTYD */
