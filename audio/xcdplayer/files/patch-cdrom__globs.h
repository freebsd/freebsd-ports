
$FreeBSD$

--- cdrom_globs.h.orig	Tue Jan 12 19:59:31 1993
+++ cdrom_globs.h	Mon Aug 25 00:38:35 2003
@@ -99,22 +99,10 @@
 extern int		cdrom_open();
 extern int		cdrom_init();
 
-
-extern Boolean		display_timer;
-
 extern XtAppContext	appc;
 
-extern char		*file;
-extern char		*device;
+#include "app.h"
+
 extern char             info_filename[];
 extern char     	*disc_title;
 extern unsigned int     timer_fsecs;
-
-
-extern float		volbase;
-extern float		volpcent;
-extern int		replayThreshold;
-extern float    	scanPauseInterval;
-extern int      	scanSkipInterval;
-extern float      	pausePauseInterval;
-extern int      	pauseSkipInterval;
