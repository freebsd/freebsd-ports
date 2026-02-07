--- uip/slocal.c.orig	2000-12-04 12:09:38 UTC
+++ uip/slocal.c
@@ -36,6 +36,10 @@ static char ident[] = "@(#)$Id: slocal.c
 #endif	/* NOIOCTLH */
 #endif	/* not V7 */
 #include <sys/stat.h>
+#include <sys/param.h>
+#if __FreeBSD_version > 900007
+#include <utmpx.h>
+#else /* __FreeBSD_version > 900007 */
 #include <utmp.h>
 #ifndef UTMP_FILENAME
 #ifdef UTMP_FILE
@@ -48,6 +52,7 @@ static char ident[] = "@(#)$Id: slocal.c
 #endif
 #endif
 #endif	/* UTMP_FILENAME */
+#endif /* __FreeBSD_version > 900007 */
 #ifdef LOCALE
 #include	<locale.h>
 #endif
@@ -938,6 +943,24 @@ register char  *key;
 
 /*  */
 
+#if __FreeBSD_version > 900007
+static int  logged_in (void) {
+    if (utmped) {
+	return utmped;
+    }
+    else {
+	struct utmpx* ut = NULL;
+
+	ut = getutxuser(user);
+	if (ut != NULL) {
+	    return (utmped = DONE);
+	}
+	else {
+	    return (utmped = NOTOK);
+	}
+    }
+}
+#else /* __FreeBSD_version > 900007 */
 static int  logged_in () {
     struct utmp ut;
     register FILE  *uf;
@@ -963,6 +986,7 @@ static int  logged_in () {
     (void) fclose (uf);
     return (utmped = NOTOK);
 }
+#endif /* __FreeBSD_version > 900007 */
 
 
 static int  timely (t1, t2)
