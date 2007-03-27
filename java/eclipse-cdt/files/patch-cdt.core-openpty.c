--- eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_3.1.2.200702150621/src/org.eclipse.cdt.core.freebsd_3.1.2.200702150621/library/openpty.c.orig	Thu Mar 30 19:18:06 2006
+++ eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_3.1.2.200702150621/src/org.eclipse.cdt.core.freebsd_3.1.2.200702150621/library/openpty.c	Thu Mar 30 19:18:47 2006
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
