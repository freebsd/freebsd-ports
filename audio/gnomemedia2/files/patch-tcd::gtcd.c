
$FreeBSD$

--- tcd/gtcd.c.orig	Mon Jun 11 20:50:57 2001
+++ tcd/gtcd.c	Fri Jul 13 12:49:33 2001
@@ -163,7 +163,11 @@
 gint release_timer(gpointer *data)
 {
 	cd.time_lock = TRUE;
+#ifdef TCD_BSD
+	ioctl(cd.cd_dev, CDIOCPAUSE);
+#else
 	ioctl(cd.cd_dev, CDROMPAUSE);
+#endif
 
 	roll_t = gtk_timeout_add(40, (GtkFunction)roll_timer, data);
 	release_t = 0;
@@ -206,7 +210,11 @@
 			if(GPOINTER_TO_INT(data) > 0)
 			{
 				if((cd.cur_t < cd.last_t) &&
+#ifdef TCD_BSD
+				   cd.trk[cd.cur_t+1].toc.control == 0x04)
+#else
 				   (cd.trk[cd.cur_t+1].toc.cdte_ctrl != CDROM_DATA_TRACK))
+#endif
 				{
 					cd.cur_t++;
 					tcd_playtracks(&cd,cd.cur_t, cd.last_t, prefs->only_use_trkind);
@@ -541,8 +549,8 @@
 		break;
 	case TRACK_R: /* track time decending */
 		cur = cd.cur_pos_rel;
-		end = (cd.trk[cd.cur_t].tot_min*60)+
-			cd.trk[cd.cur_t].tot_sec;
+		end = (TOC_MINUTE(cd.trk[cd.cur_t])*60)+
+			TOC_SECOND(cd.trk[cd.cur_t]);
 		pos = end-cur;
 		min = pos/60;
 		sec = pos-(pos/60)*60;
@@ -555,8 +563,8 @@
 		break;
 	case DISC_R:
 		cur = cd.cur_pos_abs;
-		end = (cd.trk[cd.last_t+1].toc.cdte_addr.msf.minute
-		       *60)+cd.trk[cd.last_t+1].toc.cdte_addr.msf.second;
+		end = (TOC_MINUTE(cd.trk[cd.last_t+1])*60
+		       +TOC_SECOND(cd.trk[cd.last_t+1]));
 		pos = end-cur;
 		min = pos/60;
 		sec = pos-(pos/60)*60;
@@ -660,7 +668,7 @@
 
 	if( !cd.err )
 	{
-		switch( cd.sc.cdsc_audiostatus )
+		switch( SC_AUDIOSTATUS(cd.sc) )
 		{
 		case CDROM_AUDIO_INVALID:
 			strcpy(tmp, _("No Disc"));
@@ -756,8 +764,8 @@
 	}
 
 	/* see if we need to repeat */
-	if( cd.sc.cdsc_audiostatus != CDROM_AUDIO_PLAY &&
-	    cd.sc.cdsc_audiostatus != CDROM_AUDIO_PAUSED )
+	if( SC_AUDIOSTATUS(cd.sc) != CDROM_AUDIO_PLAY &&
+	    SC_AUDIOSTATUS(cd.sc) != CDROM_AUDIO_PAUSED )
 	{
 		if( cd.play_method == REPEAT_CD )
 			tcd_playtracks( &cd, cd.first_t, cd.last_t, prefs->only_use_trkind);
@@ -774,14 +782,14 @@
 
 void status_changed(void)
 {
-	if(old_status != cd.sc.cdsc_audiostatus)
+	if(old_status != SC_AUDIOSTATUS(cd.sc))
 	{
 		GtkWidget *pixmap;
 		GtkSignalFunc func;
 		char tmp[256];
 		char *name;
 	
-		old_status = cd.sc.cdsc_audiostatus;
+		old_status = SC_AUDIOSTATUS(cd.sc);
 		g_snprintf(tmp, 255, "tcd/%s.xpm", 
 			   (old_status==CDROM_AUDIO_PLAY)?"pause":"play");
 
@@ -846,7 +854,11 @@
 
 	for(i=1; i <= cd.last_t; i++)
 	{
+#ifdef TCD_BSD
+		data_track = (cd.trk[C(i)].toc.control == 0x04);
+#else
 		data_track = (cd.trk[C(i)].toc.cdte_ctrl == CDROM_DATA_TRACK);
+#endif
 
 		g_snprintf(buf, TRK_NAME_LEN, "%2d - %s", i,
 			   data_track ? "[Data]" : cd.trk[C(i)].name);
