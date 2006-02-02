--- eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_3.0.1/src/org.eclipse.cdt.core.freebsd_3.0.1/library/openpty.c.orig	Wed Jan 11 22:04:49 2006
+++ eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_3.0.1/src/org.eclipse.cdt.core.freebsd_3.0.1/library/openpty.c	Wed Jan 11 22:52:35 2006
@@ -20,7 +20,6 @@
 #include <grp.h>
 
 #include <stdlib.h>
-#include <stropts.h>
 
 /**
  * This is taken from R. W. Stevens book.
@@ -84,7 +83,7 @@
 	char *ptr;
 
 	strcpy(pts_name, "/dev/ptmx");
-	fdm = getpt();
+	fdm = posix_openpt(O_RDWR);
 	if (fdm < 0)
 		return -1;
 	if (grantpt(fdm) < 0) { /* grant access to slave */
