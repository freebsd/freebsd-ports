
$FreeBSD$

--- tcd/tcd.c	2001/07/13 09:35:21	1.1
+++ tcd/tcd.c	2001/07/13 09:39:30
@@ -142,8 +142,8 @@
 		
 	/* if the user hasn't stopped the cd, but it is 
 	   stopped anyway, fix it. */
-	if( cd->sc.cdsc_audiostatus != CDROM_AUDIO_PLAY &&
-	    cd->sc.cdsc_audiostatus != CDROM_AUDIO_PAUSED )
+	if( SC_AUDIOSTATUS(cd->sc) != CDROM_AUDIO_PLAY &&
+	    SC_AUDIOSTATUS(cd->sc) != CDROM_AUDIO_PAUSED )
 	{
 	    if( cd->play_method == REPEAT_CD )
 		tcd_playtracks(cd, cd->first_t, cd->last_t, 0);
@@ -173,7 +173,7 @@
 	case 'p':
 	case 'P':
 	    if(cd->isplayable) {
-		if( cd->sc.cdsc_audiostatus == CDROM_AUDIO_PAUSED )
+		if( SC_AUDIOSTATUS(cd->sc) == CDROM_AUDIO_PAUSED )
 		    tcd_pausecd(cd);
 		else
 		    tcd_playtracks(cd,cd->first_t,cd->last_t, 0);
@@ -443,8 +443,8 @@
     mvwprintw(win,maxy-2,30,"Track:" );
     attron( C_RED+A_BOLD );
     mvwprintw(win,maxy-4,38,"%02u:%02u",
-	      cd->trk[C(cd->last_t+1)].toc.cdte_addr.msf.minute,
-	      cd->trk[C(cd->last_t+1)].toc.cdte_addr.msf.second );
+	      TOC_MINUTE(cd->trk[C(cd->last_t+1)]),
+	      TOC_SECOND(cd->trk[C(cd->last_t+1)]) );
     mvwprintw(win,maxy-3,38,cd->dtitle );
     attroff( C_RED+A_BOLD );
 }
@@ -481,11 +481,15 @@
     j=height;
     for(i=cd->first_t; i <= cd->last_t; i++) 
     {
-	if(cd->cur_t == i && cd->sc.cdsc_audiostatus == CDROM_AUDIO_PLAY)
+	if(cd->cur_t == i && SC_AUDIOSTATUS(cd->sc) == CDROM_AUDIO_PLAY)
 	    stat = 'P';
 	else if(cd->repeat_track == i)
 	    stat = 'R';
+#ifdef TCD_BSD
+	else if(cd->trk[i].toc.control == 0x04)
+#else
 	else if(cd->trk[i].toc.cdte_ctrl == CDROM_DATA_TRACK)
+#endif
 	    stat = 'd';
 	else
 	    stat = 'a';
@@ -501,14 +505,14 @@
 	    x = 2;
 	}
 	
-	if( cd->sc.cdsc_audiostatus == CDROM_AUDIO_PLAY && cd->cur_t == i )
+	if( SC_AUDIOSTATUS(cd->sc) == CDROM_AUDIO_PLAY && cd->cur_t == i )
 	    attron( A_BOLD );
 	
 	mvwprintw(win,y,x,"%02u%c - %02u:%02u",
 		  i, stat,cd->trk[C(i)].tot_min,
 		  cd->trk[C(i)].tot_sec );
 	
-	if(cd->sc.cdsc_audiostatus == CDROM_AUDIO_PLAY && cd->cur_t == i)
+	if(SC_AUDIOSTATUS(cd->sc) == CDROM_AUDIO_PLAY && cd->cur_t == i)
 	    attroff( A_BOLD );
     }	
 }
@@ -519,7 +523,7 @@
 	
     if( !cd->err )
     {
-	switch( cd->sc.cdsc_audiostatus )
+	switch( SC_AUDIOSTATUS(cd->sc) )
 	{
 	case CDROM_AUDIO_INVALID:
 	    strcpy( tmp,"No Audio         " );
