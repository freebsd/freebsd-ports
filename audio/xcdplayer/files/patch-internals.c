
$FreeBSD$

--- internals.c.orig	Tue Jan 12 19:59:45 1993
+++ internals.c	Mon Aug 25 00:38:35 2003
@@ -22,6 +22,9 @@
 
 # include "debug.h"
 # include "cdrom_globs.h"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+# include "cdrom_freebsd.h"
+#endif
 #ifdef sun
 # include "cdrom_sun.h"
 #endif
@@ -29,13 +32,14 @@
 # include "cdrom_sgi.h"
 #endif
 
-
+static void     scan_update();
 static XtIntervalId	ivid			= -1;
 static XtIntervalId	scanivid		= -1;
 static XtIntervalId	stativid		= -1;
 static unsigned int	timer_mod		= 1000 / TIMER_PERIOD;
 unsigned int		timer_fsecs;
 
+extern AppData app_data;
 
 int
 cdrom_get_curtime() {
@@ -170,7 +174,6 @@
 	struct msf	track_start;
         struct msf	start_addr, end_addr;
 	int		curtrack;
-	extern void 	scan_update();
 
 	if (cdrom_get_curmsf(&start_addr) == -1) {
 		debug_printf(1, "rew: error reading location\n");
@@ -196,11 +199,11 @@
 	    if (((cdi.state & CDROM_STATE_PLAY) && 
 		 ((track_start.minute * 60) + track_start.second) >=
 		 ((start_addr.minute * 60) + start_addr.second - 
-		  scanSkipInterval)) ||
+		  app_data.scanSkipInterval)) ||
 		((cdi.state & CDROM_STATE_PAUSE) &&
 		 ((track_start.minute * 60) + track_start.second) >=
 		 ((start_addr.minute * 60) + start_addr.second -
-		  pauseSkipInterval)))
+		  app_data.pauseSkipInterval)))
 	    {
 	        start_addr = track_start;
 	        start_addr.second++; /* guarantee we never back up too far */
@@ -208,9 +211,9 @@
 	    else
 	    {
 		if (cdi.state & CDROM_STATE_PAUSE) {
-			start_addr.second -= pauseSkipInterval; 
+			start_addr.second -= app_data.pauseSkipInterval; 
 		} else if (cdi.state & CDROM_STATE_PLAY) {
-			start_addr.second -= scanSkipInterval; 
+			start_addr.second -= app_data.scanSkipInterval; 
 		}
 	        if ((char) start_addr.second < 0)
 	        {
@@ -223,9 +226,9 @@
 	else /* normal case */
 	{
 		if (cdi.state & CDROM_STATE_PAUSE) {
-			start_addr.second -= pauseSkipInterval; 
+			start_addr.second -= app_data.pauseSkipInterval; 
 		} else if (cdi.state & CDROM_STATE_PLAY) {
-			start_addr.second -= scanSkipInterval; 
+			start_addr.second -= app_data.scanSkipInterval; 
 		}
 		if ((char) start_addr.second < 0)
 		{
@@ -274,7 +277,7 @@
 	{
 	    if (scanivid == -1)
 		scanivid = XtAppAddTimeOut(appc, 
-			(int)(pausePauseInterval * 1000.0), 
+			(int)(app_data.pausePauseInterval * 1000.0), 
 			scan_update, NULL);
 
 	    cdi.state &= ~CDROM_STATE_PAUSE;	/* allow timer to change */
@@ -304,7 +307,6 @@
         struct msf	start_addr, end_addr,  next_start;
 	char		t;
 	int		curtrack;
-	extern void 	scan_update();
 
 	if (cdrom_get_curmsf(&start_addr) == -1) {
 		debug_printf(1, "ff: error reading location\n");
@@ -332,11 +334,11 @@
 	    if (((cdi.state & CDROM_STATE_PLAY) && 
 		 ((next_start.minute * 60) + next_start.second) <=
 		 ((start_addr.minute * 60) + start_addr.second +
-		  scanSkipInterval)) ||
+		  app_data.scanSkipInterval)) ||
 		((cdi.state & CDROM_STATE_PAUSE) &&
 		 ((next_start.minute * 60) + next_start.second) <=
 		 ((start_addr.minute * 60) + start_addr.second +
-		  pauseSkipInterval)))
+		  app_data.pauseSkipInterval)))
 	    {
 	    
 	        /* start at end of current track */
@@ -346,9 +348,9 @@
 	    else
 	    {
 		    if (cdi.state & CDROM_STATE_PAUSE) {
-			    start_addr.second += pauseSkipInterval; 
+			    start_addr.second += app_data.pauseSkipInterval; 
 		    } else if (cdi.state & CDROM_STATE_PLAY) {
-			    start_addr.second += scanSkipInterval; 
+			    start_addr.second += app_data.scanSkipInterval; 
 		    }
 		    if (start_addr.second >= 60)
 		    {
@@ -360,9 +362,9 @@
 	else
 	{
 	    if (cdi.state & CDROM_STATE_PAUSE) {
-		start_addr.second += pauseSkipInterval; 
+		start_addr.second += app_data.pauseSkipInterval; 
 	    } else if (cdi.state & CDROM_STATE_PLAY) {
-		start_addr.second += scanSkipInterval; 
+		start_addr.second += app_data.scanSkipInterval; 
 	    }
 	    if (start_addr.second >= 60)
 	    {
@@ -413,7 +415,7 @@
 	{
 	    if (scanivid == -1)
 		scanivid = XtAppAddTimeOut(appc, 
-			(int)(pausePauseInterval * 1000.0), 
+			(int)(app_data.pausePauseInterval * 1000.0), 
 			scan_update, NULL);
 
 	    cdi.state &= ~CDROM_STATE_PAUSE;	/* allow timer to change */
@@ -557,7 +559,7 @@
 				 cdi.state &= ~CDROM_STATE_STOP;
 		}
 	        ivid = XtAppAddTimeOut(appc, 
-			(int)(scanPauseInterval * 1000.0), 
+			(int)(app_data.scanPauseInterval * 1000.0), 
 			scan_update, NULL);
 	}
 	else
@@ -574,7 +576,7 @@
 			}
 
 			ivid = XtAppAddTimeOut(appc,
-				(int)(scanPauseInterval * 1000.0),
+				(int)(app_data.scanPauseInterval * 1000.0),
 				scan_update, NULL);
 		}
 		else if (scanivid != -1) {
@@ -662,7 +664,7 @@
 				 cdi.state &= ~CDROM_STATE_STOP;
 		}
 	        ivid = XtAppAddTimeOut(appc, 
-			(int)(scanPauseInterval * 1000.0), 
+			(int)(app_data.scanPauseInterval * 1000.0), 
 			update_track, NULL);
 	}
 	else
@@ -679,7 +681,7 @@
 			}
 
 			ivid = XtAppAddTimeOut(appc,
-				(int)(scanPauseInterval * 1000.0),
+				(int)(app_data.scanPauseInterval * 1000.0),
 				update_track, NULL);
 		}
 		else
