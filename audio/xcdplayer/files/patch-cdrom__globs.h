--- cdrom_globs.h.orig	1993-01-12 18:59:31 UTC
+++ cdrom_globs.h
@@ -99,22 +99,10 @@ extern void		program_cancel();
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
