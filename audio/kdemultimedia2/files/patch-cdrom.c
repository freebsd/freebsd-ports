--- kscd/libwm/cdrom.c	Mon Jun 18 07:01:07 2001
+++ kscd/libwm/cdrom.c.new	Thu Nov 29 21:37:42 2001
@@ -182,6 +182,13 @@
         struct wm_playlist *l;
         int    i;
         int    pos;
+
+	if(drive.get_trackcount == NULL)
+	{
+		perror("trackcount: function pointer NULL");
+		return (NULL);
+	}
+
 	if ((drive.get_trackcount)(&drive, &thiscd.ntracks) < 0)
 	{
 		perror("trackcount");
@@ -217,6 +224,12 @@
 
 	for (i = 0; i < thiscd.ntracks; i++)
 	{
+		if(drive.get_trackinfo == NULL)
+		{
+			perror("CD track info read: function pointer null");
+			return (NULL);
+		}
+
 		if ((drive.get_trackinfo)(&drive, i + 1, &thiscd.trk[i].data,
 					&thiscd.trk[i].start) < 0)
 		{
@@ -235,6 +248,12 @@
 		thiscd.trk[i].section = 0;
 	}
 
+	if(drive.get_cdlen == NULL)
+	{
+		perror("CD length read: function pointer null");
+		return (NULL);
+	}
+
 	if ((drive.get_cdlen)(&drive, &thiscd.trk[i].start) < 0)
 	{
 		perror("CD length read");
@@ -305,6 +324,12 @@
 	if( (cur_cdmode == WM_CDM_STOPPED) || (cur_cdmode == WM_CDM_PLAYING) )
 		oldmode = cur_cdmode;
 
+	if(drive.get_drive_status == NULL)
+	{
+		perror("CD get drive status: function pointer NULL");
+		return (-1);
+	}
+
 	if( (drive.get_drive_status)(&drive, oldmode, &mode, &cur_frame,
 					&trackno, &cur_index) < 0)
 	{
@@ -474,7 +499,8 @@
 	right = right < 0 ? 0 : right > 100 ? 100 : right;
 /*	printf("Left = %d, Right = %d\n", left, right);
 */
-	(void) (drive.set_volume)(&drive, left, right);
+	if(drive.set_volume != NULL)
+		(void) (drive.set_volume)(&drive, left, right);
 } /* cd_volume() */
 
 #else
@@ -513,7 +539,8 @@
 	if (right > 100)
 		right = 100;
 
-	(void) (drive.set_volume)(&drive, left, right);
+	if(drive.set_volume != NULL)
+		(void) (drive.set_volume)(&drive, left, right);
 } /* cd_volume() */
 
 #endif /* CLIF_VOL */
@@ -536,18 +563,20 @@
 	switch (cur_cdmode) {
 	case WM_CDM_PLAYING:		/* playing */
 		cur_cdmode = WM_CDM_PAUSED;
-		(drive.pause)(&drive);
-                paused_pos = cur_pos_rel;
+		if(drive.pause != NULL)
+			(drive.pause)(&drive);
+
+		paused_pos = cur_pos_rel;
 		break;
 
 	case WM_CDM_PAUSED:		/* paused */
 		cur_cdmode = WM_CDM_PLAYING;
 /*		(drive.resume)(&drive); */
-		if ((drive.resume)(&drive) > 0 )
-                  {
-			wm_cd_play(cur_track, paused_pos,
-				playlist[cur_listno-1].end);
-                  }
+		if(drive.resume != NULL)
+			if ((drive.resume)(&drive) > 0 )
+      	wm_cd_play(cur_track, paused_pos, playlist[cur_listno-1].end);
+		break;
+
 	default: /* */
 		break;	
 	}
@@ -568,7 +597,10 @@
 	{
 		cur_lasttrack = cur_firsttrack = -1;
 		cur_cdmode = WM_CDM_STOPPED;
-		(drive.stop)(&drive);
+		
+    if(drive.stop != NULL)
+			(drive.stop)(&drive);
+
 		cur_track = 1;
 	}
 } /* wm_cd_stop() */
@@ -595,7 +627,8 @@
 	if (start >= end)
 		start = end-1;
 
-	(drive.play)(&drive, start, end, realstart);
+	if(drive.play != NULL)
+		(drive.play)(&drive, start, end, realstart);
 }
 
 /*
@@ -681,6 +714,12 @@
 {
 	int	status;
 
+	if(drive.eject == NULL)
+	{
+		perror("Could not eject CD: function pointer NULL");
+		return (1);
+	}
+
 	status = (drive.eject)(&drive);
 	if (status < 0)
 	{
@@ -705,6 +744,12 @@
 
 int wm_cd_closetray(void)
 {
+	if(drive.closetray == NULL)
+	{
+		perror("Could not close drive tray: function pointer NULL");
+		return (1);
+	}
+
 	return((drive.closetray)(&drive) ? 0 : wm_cd_status()==2 ? 1 : 0);
 } /* wm_cd_closetray() */
 
@@ -785,8 +830,9 @@
 {
 	int	left, right;
 
-	if ((drive.get_volume)(&drive, &left, &right) < 0 || left == -1)
-		return (max);
+	if(drive.get_volume != NULL)
+		if ((drive.get_volume)(&drive, &left, &right) < 0 || left == -1)
+			return (max);
 
 	left = (left * max + 99) / 100;
 	right = (right * max + 99) / 100;
