--- uip/slocal.c.orig	2000-12-04 21:09:38.000000000 +0900
+++ uip/slocal.c	2010-04-12 17:10:12.000000000 +0900
@@ -36,6 +36,10 @@
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
@@ -48,6 +52,7 @@
 #endif
 #endif
 #endif	/* UTMP_FILENAME */
+#endif /* __FreeBSD_version > 900007 */
 #ifdef LOCALE
 #include	<locale.h>
 #endif
@@ -938,6 +943,24 @@
 
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
@@ -963,6 +986,7 @@
     (void) fclose (uf);
     return (utmped = NOTOK);
 }
+#endif /* __FreeBSD_version > 900007 */
 
 
 static int  timely (t1, t2)
