
$NetBSD: pkgsrc/audio/xcdplayer/patches/patch-ae,v 1.4 2005/12/11 20:48:46 joerg Exp $

--- cdrom_callb.c.orig	1993-01-12 18:59:48 UTC
+++ cdrom_callb.c
@@ -22,6 +22,9 @@
 
 # include "debug.h"
 # include "cdrom_globs.h"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
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
@@ -287,7 +292,7 @@ cb_cdrom_previous(widget, client_data, c
 	 * if playing less than replayThreshold seconds, back up to 
 	 * previous track; otherwise start at beginning of current track:
 	 */
-	if (cdi.duration < replayThreshold)
+	if (cdi.duration < app_data.replayThreshold)
 	{
 	    if ((cdi.program != NULL) &&
 	    	 (cdi.state & CDROM_STATE_PLAY) &&
