
$FreeBSD$

--- cdrom_callb.c.orig	Tue Jan 12 19:59:48 1993
+++ cdrom_callb.c	Mon Aug 25 00:38:35 2003
@@ -22,6 +22,9 @@
 
 # include "debug.h"
 # include "cdrom_globs.h"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+# include "cdrom_freebsd.h"
+#endif
 #ifdef sun
 # include "cdrom_sun.h"
 #endif
@@ -29,6 +32,8 @@
 # include "cdrom_sgi.h"
 #endif
 
+extern AppData app_data;
+
 void		cdrom_new_disc();
 
 /*
@@ -287,7 +292,7 @@
 	 * if playing less than replayThreshold seconds, back up to 
 	 * previous track; otherwise start at beginning of current track:
 	 */
-	if (cdi.duration < replayThreshold)
+	if (cdi.duration < app_data.replayThreshold)
 	{
 	    if ((cdi.program != NULL) &&
 	    	 (cdi.state & CDROM_STATE_PLAY) &&
