--- tcd/linux-cdrom.c.orig	Mon Jun 11 13:50:58 2001
+++ tcd/linux-cdrom.c	Tue Apr 16 15:55:46 2002
@@ -67,6 +67,7 @@
     return;
 }
 
+#ifndef TCD_BSD
 static void decrement_msf_end_by_one (struct cdrom_msf *msf)
 {
     if (msf->cdmsf_frame1)
@@ -87,13 +88,14 @@
 	}
     }
 }
+#endif
 
 int tcd_init_disc( cd_struct *cd, WarnFunc msg_cb )
 {
     debug("cdrom.c: tcd_init_disc(%p) top\n", cd );
     tcd_opencddev( cd, msg_cb );
     
-#if defined(TCD_CHANGER_ENABLED)
+#if defined(TCD_CHANGER_ENABLED) && !defined(TCD_BSD)
     cd->nslots = ioctl( cd->cd_dev, CDROM_CHANGER_NSLOTS );
 #else
     cd->nslots = 0;
@@ -131,6 +133,9 @@
 int tcd_close_disc( cd_struct *cd )
 {
     debug("cdrom.c: tcd_close_disc(%p) top\n", cd );
+#ifdef TCD_BSD
+    ioctl( cd->cd_dev, CDIOCALLOW);
+#endif
     close(cd->cd_dev);
     cd->cd_dev = -1;
     debug("cdrom.c: tcd_close_disc exiting normally\n" );
@@ -141,6 +146,10 @@
 {
     int i;
     int delsecs;
+#ifdef TCD_BSD
+    struct ioc_read_toc_single_entry tocentry;
+#endif
+
 
     if(cd->time_lock)
 	    return;
@@ -152,7 +161,11 @@
     cd->isplayable=FALSE;
 	
     /* read the TOC header */
+#ifdef TCD_BSD
+    if((ioctl( cd->cd_dev, CDIOREADTOCHEADER, &cd->tochdr))==-1)
+#else
     if(ioctl( cd->cd_dev, CDROMREADTOCHDR, &cd->tochdr))
+#endif
     {
 	strcpy( cd->errmsg, "Can't read disc." );
 	cd->err = TRUE;
@@ -164,15 +177,29 @@
     }
 
     /* grab first & last tracks */
+#ifdef TCD_BSD
+    cd->first_t = cd->tochdr.starting_track;
+    cd->last_t = cd->tochdr.ending_track;
+#else
     cd->first_t = cd->tochdr.cdth_trk0;
     cd->last_t = cd->tochdr.cdth_trk1;
+#endif
 
     /* read the leadout track */
+#ifdef TCD_BSD
+    tocentry.track = 0xaa;   /* Magic last track */
+    tocentry.address_format = CD_MSF_FORMAT;
+#else
     cd->trk[C(cd->last_t+1)].toc.cdte_track = CDROM_LEADOUT;
     cd->trk[C(cd->last_t+1)].toc.cdte_format = CDROM_MSF;
+#endif
 
     /* read the leadout toc */
+#ifdef TCD_BSD
+    if((ioctl(cd->cd_dev, CDIOREADTOCENTRY, &tocentry)) == -1)
+#else
     if(ioctl(cd->cd_dev, CDROMREADTOCENTRY, &cd->trk[C(cd->last_t+1)].toc))
+#endif
     {
 	strcpy(cd->errmsg, "Can't read disc.");
 	cd->err = TRUE;
@@ -184,13 +211,30 @@
 	return;
     }                                         
 
+#ifdef TCD_BSD
+    cd->trk[C(cd->last_t+1)].toc = tocentry.entry;
+    cd->trk[C(cd->last_t+1)].length = TOC_MINUTE(cd->trk[C(cd->last_t+1)]) * 60 +
+	TOC_SECOND(cd->trk[C(cd->last_t+1)]);
+    cd->trk[C(cd->last_t+1)].start = cd->trk[C(cd->last_t+1)].length * 75 +
+	TOC_FRAME(cd->trk[C(cd->last_t+1)]);
+#endif
+
     /* read the rest of the tocs */
     for( i = cd->first_t; i <= cd->last_t; i++ )
     {
+#ifdef TCD_BSD
+	tocentry.track = i;
+	tocentry.address_format = CD_MSF_FORMAT;
+#else
 	cd->trk[C(i)].toc.cdte_track = i;
 	cd->trk[C(i)].toc.cdte_format = CDROM_MSF;
+#endif
 	
+#ifdef TCD_BSD
+	if((ioctl(cd->cd_dev, CDIOREADTOCENTRY, &tocentry)) == -1)
+#else
 	if(ioctl(cd->cd_dev, CDROMREADTOCENTRY, &cd->trk[C(i)].toc))
+#endif
 	{
 	    strcpy( cd->errmsg, "Can't read disc." );
 	    cd->err = TRUE;
@@ -201,21 +245,34 @@
 	    return;
 	}
 
+#ifdef TCD_BSD
+	cd->trk[C(i)].toc = tocentry.entry;
+	cd->trk[C(i)].type = cd->trk[C(i)].toc.control;
+	cd->trk[C(i)].length = TOC_MINUTE(cd->trk[C(i)]) * 60 +
+	    TOC_SECOND(cd->trk[C(i)]);
+	cd->trk[C(i)].start = cd->trk[C(i)].length * 75 +
+	    TOC_FRAME(cd->trk[C(i)]);
+#else
 	cd->trk[C(i)].type = cd->trk[C(i)].toc.cdte_ctrl;
 	cd->trk[C(i)].length = cd->trk[C(i)].toc.cdte_addr.msf.minute * 60 +
 	    cd->trk[C(i)].toc.cdte_addr.msf.second;
 	cd->trk[C(i)].start = cd->trk[C(i)].length * 75 + 
 	    cd->trk[C(i)].toc.cdte_addr.msf.frame;
+#endif
     }
 
     /* calculate track times */
     for(i = cd->first_t; i <= cd->last_t; i ++)
     {
 	/* Taken from cdtool...Thanks Thomas I.! */
+#ifdef TCD_BSD
+	delsecs = cd->trk[C(i+1)].length - cd->trk[C(i)].length;
+#else
 	delsecs = cd->trk[C(i+1)].toc.cdte_addr.msf.minute * 60
 	    + cd->trk[C(i+1)].toc.cdte_addr.msf.second
 	    - cd->trk[C(i)].toc.cdte_addr.msf.minute * 60
 	    - cd->trk[C(i)].toc.cdte_addr.msf.second;
+#endif
 
 	cd->trk[C(i)].tot_min = delsecs / 60;
 	cd->trk[C(i)].tot_sec = delsecs - (delsecs/60)*60;
@@ -245,9 +302,14 @@
 	    return;
 
     /* calculate various timing values */
+#ifdef TCD_BSD
+    cd->cur_pos_abs = SC_MINUTE(cd->sc) * 60 + SC_SECOND(cd->sc);
+    cd->cur_frame = cd->cur_pos_abs * 75 + SC_FRAME(cd->sc);
+#else
     cd->cur_pos_abs = cd->sc.cdsc_absaddr.msf.minute * 60 +
 	cd->sc.cdsc_absaddr.msf.second;
     cd->cur_frame = cd->cur_pos_abs * 75 + cd->sc.cdsc_absaddr.msf.frame;
+#endif
         
     cd->cur_pos_rel = (cd->cur_frame - cd->trk[C(cd->cur_t)].start) / 75;
 	
@@ -266,10 +328,12 @@
     cd->cd_min = cd->cur_pos_abs / 60;
 
 #ifdef TCD_CHANGER_ENABLED
+#ifndef TCD_BSD
     tcd_opencddev( cd, NULL );
     cd->cur_disc = ioctl( cd->cd_dev, CDROM_SELECT_DISC, CDSL_CURRENT );
     tcd_close_disc ( cd );
 #endif
+#endif
 }
 
 void tcd_recalculate_fake(cd_struct *cd, gint abs_pos, gint track)
@@ -305,7 +369,11 @@
 	
 	for(t = cd->first_t; t <= cd->last_t; t++)
 	{
+#ifdef TCD_BSD
+		if(cd->trk[t].toc.control == 0x04)
+#else
 		if(cd->trk[t].toc.cdte_ctrl == CDROM_DATA_TRACK)
+#endif
 			return t-1;
 		if(abs_pos >= cd->trk[t].start/75)
 			continue;
@@ -316,16 +384,35 @@
 
 void tcd_gettime( cd_struct *cd )
 {
+#ifdef TCD_BSD
+	struct ioc_read_subchannel subch;
+#endif
 	cd->err = FALSE;
+#ifdef TCD_BSD
+	subch.address_format = CD_MSF_FORMAT;
+	subch.data_format = CD_CURRENT_POSITION;
+	subch.data_len = sizeof(cd->sc);
+	subch.track = 0;
+	subch.data = &(cd->sc);
+#else
 	cd->sc.cdsc_format = CDROM_MSF;
+#endif
 	
 	if(cd->isplayable)
 	{
 	        int tmp;
 		tcd_opencddev (cd, NULL);
+#ifdef TCD_BSD
+		tmp = ioctl( cd->cd_dev, CDIOCREADSUBCHANNEL, &subch);
+#else
 		tmp = ioctl( cd->cd_dev, CDROMSUBCHNL, &cd->sc);
+#endif
 		tcd_close_disc (cd);
+#ifdef TCD_BSD
+		if(tmp == -1)
+#else
 		if(tmp)
+#endif
 		{
 			strcpy( cd->errmsg, "Can't read disc." );
 			cd->err = TRUE;
@@ -333,8 +420,18 @@
 			cd->cur_t = 0;
 			return;
 		}
+#ifdef TCD_BSD
+		if( SC_AUDIOSTATUS(cd->sc)==CDROM_AUDIO_PLAY )
+#else
 		if(cd->sc.cdsc_audiostatus==CDROM_AUDIO_PLAY)
+#endif
+		{
+#ifdef TCD_BSD
+			cd->cur_t = SC_TRACK(cd->sc);
+#else
 			cd->cur_t = cd->sc.cdsc_trk;
+#endif
+		}
 		else
 			cd->cur_t = 0;
 		tcd_recalculate(cd);
@@ -343,14 +440,27 @@
 
 int tcd_set_volume(cd_struct *cd, int volume)
 {
+#ifdef TCD_BSD
+    struct ioc_vol vol;
+#else
     struct cdrom_volctrl vol;
+#endif
     int tmp;
 
+#ifdef TCD_BSD
+    vol.vol[0] = volume;
+    vol.vol[1] = vol.vol[2] = vol.vol[3] = vol.vol[0];
+#else
     vol.channel0 = volume;
     vol.channel1 = vol.channel2 = vol.channel3 = vol.channel0;
+#endif
 
     tcd_opencddev( cd, NULL );
+#ifdef TCD_BSD
+    tmp = ioctl(cd->cd_dev, CDIOCSETVOL, &vol);
+#else
     tmp = ioctl(cd->cd_dev, CDROMVOLCTRL, &vol);
+#endif
     tcd_close_disc ( cd );
     if(tmp < 0)
 	return FALSE;
@@ -360,6 +470,18 @@
 
 int tcd_get_volume(cd_struct *cd)
 {
+#ifdef TCD_BSD
+    struct ioc_vol vol;
+    int tmp;
+
+    tcd_opencddev( cd, NULL );
+    tmp = ioctl(cd->cd_dev, CDIOCGETVOL, &vol);
+    tcd_close_disc ( cd );
+    if (tmp < 0)
+	return -1;
+
+    return vol.vol[0];
+#else
 #ifdef CDROMVOLREAD
     struct cdrom_volctrl vol;
     int tmp;
@@ -374,12 +496,38 @@
 #else
     return 0;
 #endif
+#endif
 }	
 	                                  
 void tcd_playtracks(cd_struct *cd, int start_t, int end_t, int only_use_trkind)
 {
+#ifdef TCD_BSD
+    struct ioc_play_msf msf;
+#define MSF_START_MIN  (msf.start_m)
+#define MSF_START_SEC  (msf.start_s)
+#define MSF_START_FRM  (msf.start_f)
+#define MSF_END_MIN    (msf.end_m)
+#define MSF_END_SEC    (msf.end_s)
+#define MSF_END_FRM    (msf.end_f)
+    struct ioc_play_track trkind;
+#define TI_START_TRK   (trkind.start_track)
+#define TI_START_IND   (trkind.start_index)
+#define TI_END_TRK     (trkind.end_track)
+#define TI_END_IND     (trkind.end_index)
+#else
     struct cdrom_msf msf;
+#define MSF_START_MIN  (msf.cdmsf_min0)
+#define MSF_START_SEC  (msf.cdmsf_sec0)
+#define MSF_START_FRM  (msf.cdmsf_frame0)
+#define MSF_END_MIN    (msf.cdmsf_min1)
+#define MSF_END_SEC    (msf.cdmsf_sec1)
+#define MSF_END_FRM    (msf.cdmsf_frame0)
     struct cdrom_ti trkind;
+#define TI_START_TRK   (trkind.cdti_trk0)
+#define TI_START_IND   (trkind.cdti_ind0)
+#define TI_END_TRK     (trkind.cdti_trk1)
+#define TI_END_IND     (trkind.cdti_ind1)
+#endif
     debug("cdrom.c: tcd_playtracks( %p, %d, %d )\n", cd, start_t, end_t );
     cd->err = FALSE;
 	
@@ -390,7 +538,7 @@
     tcd_gettime(cd);
     if(cd->err) 
     {
-	/* try and inject cd */
+	/* try and eject cd */
 	tcd_ejectcd(cd);
 
 	if(cd->err) 
@@ -401,62 +549,79 @@
     }
 
     tcd_opencddev( cd, NULL );
+#ifdef TCD_BSD
+    ioctl(cd->cd_dev, CDIOCCLOSE);
+#else
 #if defined(CDROMCLOSETRAY)
     if( ioctl( cd->cd_dev, CDROM_DRIVE_STATUS ) == CDS_TRAY_OPEN )
 	    ioctl(cd->cd_dev, CDROMCLOSETRAY);
 #endif	        
+#endif
 	
+#ifdef TCD_BSD
+    if(cd->trk[start_t].toc.control == 0x04)
+#else
     if(cd->trk[start_t].toc.cdte_ctrl == CDROM_DATA_TRACK)
+#endif
 	start_t++;		/* bad hack. most data tracks are the first track... */
 
-    msf.cdmsf_min0 = cd->trk[start_t].toc.cdte_addr.msf.minute;
-    msf.cdmsf_sec0 = cd->trk[start_t].toc.cdte_addr.msf.second;
-    msf.cdmsf_frame0 = cd->trk[start_t].toc.cdte_addr.msf.frame;
+    MSF_START_MIN = TOC_MINUTE(cd->trk[start_t]);
+    MSF_START_SEC = TOC_SECOND(cd->trk[start_t]);
+    MSF_START_FRM = TOC_FRAME(cd->trk[start_t]);
 	
     if( end_t < 0 )
     {
-	msf.cdmsf_min1 = cd->trk[start_t].tot_min+msf.cdmsf_min0;
-	msf.cdmsf_sec1 = cd->trk[start_t].tot_sec+msf.cdmsf_sec0;
-	msf.cdmsf_frame1=0;
+	MSF_END_MIN = cd->trk[start_t].tot_min+MSF_START_MIN;
+	MSF_END_SEC = cd->trk[start_t].tot_sec+MSF_START_SEC;
+	MSF_END_FRM = 0;
     }
     else
     {
-	msf.cdmsf_min1 = cd->trk[end_t+1].toc.cdte_addr.msf.minute;
-	msf.cdmsf_sec1 = cd->trk[end_t+1].toc.cdte_addr.msf.second;
-	msf.cdmsf_frame1 = cd->trk[end_t+1].toc.cdte_addr.msf.frame;
-	decrement_msf_end_by_one (&msf);
+	MSF_END_MIN = TOC_MINUTE(cd->trk[end_t+1]);
+	MSF_END_SEC = TOC_SECOND(cd->trk[end_t+1]);
+	MSF_END_FRM = TOC_FRAME(cd->trk[end_t+1]);
+	MSF_END_FRM -= 1;
 
 #ifdef UNSIGNED_NUMBERS_CAN_BE_NEGATIVE
-	if(msf.cdmsf_frame1 < 0)
+	if(MSF_END_FRM < 0)
 	{
-	    msf.cdmsf_sec1 += msf.cdmsf_frame1;
-	    msf.cdmsf_frame1 = 0;
+	    MSF_END_SEC += MSF_END_FRM;
+	    MSF_END_FRM = 0;
 	}
-	if(msf.cdmsf_sec1 < 0)
+	if(MSF_END_SEC < 0)
 	{
-	    msf.cdmsf_min1 += msf.cdmsf_sec1;
-	    msf.cdmsf_sec1 = 0;
+	    MSF_END_MIN += MSF_END_SEC;
+	    MSF_END_SEC = 0;
 	}
-	if(msf.cdmsf_min1 < 0)
+	if(MSF_END_MIN < 0)
 	{
-	    msf.cdmsf_min1 = 0;
+	    MSF_END_MIN = 0;
 	}
 #endif
     }
-    msf.cdmsf_min1 += (msf.cdmsf_sec1 / 60);
-    msf.cdmsf_sec1 %= 60;
+    MSF_END_MIN += (MSF_END_SEC / 60);
+    MSF_END_SEC %= 60;
 
+#ifdef TCD_BSD
+    ioctl( cd->cd_dev, CDIOCPREVENT);
+    if(only_use_trkind || ioctl( cd->cd_dev, CDIOCPLAYMSF, &msf))
+#else
     if(ioctl( cd->cd_dev, CDROMPLAYMSF, &msf) || only_use_trkind)
+#endif
     {
 	debug("cdrom.c: tcd_playtracks error. CDROMPLAYMSF ioctl error (or user override). Trying PLAYTRKIND\n" );
 
 	/* Try alternate method of playing */
-	trkind.cdti_trk0 = start_t;     /* start track */
-	trkind.cdti_ind0 = 0;      	/* start index */
-	trkind.cdti_trk1 = end_t;      	/* end track */
-	trkind.cdti_ind1 = 0;      	/* end index */
+	TI_START_TRK = start_t;		/* start track */
+	TI_START_IND = 0;	      	/* start index */
+	TI_END_TRK = end_t;      	/* end track */
+	TI_END_IND = 0;         	/* end index */
 		                                
+#ifdef TCD_BSD
+	if(ioctl(cd->cd_dev, CDIOCPLAYTRACKS, &trkind))
+#else
 	if(ioctl(cd->cd_dev, CDROMPLAYTRKIND, &trkind))
+#endif
 	{
 	    strcpy( cd->errmsg, "Error playing disc" );
 	    cd->err = TRUE;
@@ -472,25 +637,15 @@
     return;
 }       
 
-static int msf_2_frame( cd_min_sec_frame *msf )
-{
-	return( ( msf->minute * CD_SECS + msf->second )
-			* CD_FRAMES + msf->frame );
-}
-
-static void frame_2_msf( int frame, cd_min_sec_frame *msf )
-{
-	msf->frame = frame % CD_FRAMES;
-	frame /= CD_FRAMES;
-	msf->second = frame % CD_SECS;
-	msf->minute = frame / CD_SECS;
-}
-
 int tcd_play_seconds( cd_struct *cd, long int offset )
 {
+#ifdef TCD_BSD
+    struct ioc_play_msf msf;
+#else
     struct cdrom_msf msf;
     cd_min_sec_frame msf0;
     int cur_frame, start_frame, end_frame;
+#endif
     int tmp;
 
     debug("cdrom.c: tcd_play_seconds( %p, %ld )\n", cd, offset );
@@ -498,53 +653,54 @@
     cd->err = FALSE;
     cd->isplayable=FALSE;
 
-    /* converting msf to frames makes life much easier */
-    start_frame = msf_2_frame( &cd->trk[C(cd->first_t)].toc.cdte_addr.msf );
-    end_frame = msf_2_frame( &cd->trk[C(cd->last_t+1)].toc.cdte_addr.msf ) - 1;
-    cur_frame = cd->cur_frame + ( offset * CD_FRAMES );
-
-    /* keep the cur_frame within the boundaries of the first and last track */
-    if ( cur_frame < start_frame ) {
-	    cur_frame = start_frame;
-    } else if ( cur_frame > end_frame ) {
-	    cur_frame = end_frame;
-    }
-
-    /* convert frames back to msf */
-    frame_2_msf( cur_frame, &msf0 );
-    msf.cdmsf_min0 = msf0.minute;
-    msf.cdmsf_sec0 = msf0.second;
-    msf.cdmsf_frame0 = msf0.frame;
-    msf.cdmsf_min1 = cd->trk[C(cd->last_t+1)].toc.cdte_addr.msf.minute;
-    msf.cdmsf_sec1 = cd->trk[C(cd->last_t+1)].toc.cdte_addr.msf.second;
-    msf.cdmsf_frame1 = cd->trk[C(cd->last_t+1)].toc.cdte_addr.msf.frame;
-    decrement_msf_end_by_one (&msf);
+    /* got subchannel? */
+    MSF_START_SEC = SC_SECOND(cd->sc)+offset;
+    MSF_START_MIN = SC_MINUTE(cd->sc);
+    MSF_START_FRM = SC_FRAME(cd->sc);
+    MSF_END_MIN = TOC_MINUTE(cd->trk[C(cd->last_t+1)]);
+    MSF_END_SEC = TOC_SECOND(cd->trk[C(cd->last_t+1)]);
+    MSF_END_FRM = TOC_FRAME(cd->trk[C(cd->last_t+1)]);
+    MSF_END_FRM -= 1;
  
 #ifdef UNSIGNED_NUMBERS_CAN_BE_NEGATIVE
-    if(msf.cdmsf_frame1 < 0)
+    if((MSF_END_FRM < 0)
     {
-	msf.cdmsf_sec1 += msf.cdmsf_frame1;
-	msf.cdmsf_frame1 = 0;
+	MSF_END_SEC += MSF_END_FRM;
+	MSF_END_FRM = 0;
     }
-    if(msf.cdmsf_sec1 < 0)
+    if(MSF_END_SEC < 0)
     {
-	msf.cdmsf_min1 += msf.cdmsf_sec1;
-	msf.cdmsf_sec1 = 0;
+	MSF_END_MIN += MSF_END_SEC;
+	MSF_END_SEC = 0;
     }
-    if(msf.cdmsf_min1 < 0)
+    if(MSF_END_MIN < 0)
     {
-	msf.cdmsf_min1 = 0;
+	MSF_END_MIN = 0;
     }
 #endif
-	
+
+    if(MSF_START_SEC > 60 && (offset<0))
+    {
+	MSF_START_SEC = 60-abs(offset);
+	MSF_START_MIN--;
+    }
+
     tcd_opencddev( cd, NULL );
+#ifdef TCD_BSD
+    ioctl( cd->cd_dev, CDIOCPREVENT );
+    tmp = ioctl(cd->cd_dev, CDIOCPLAYMSF, &msf);
+#else
     tmp = ioctl(cd->cd_dev, CDROMPLAYMSF, &msf);
+#endif
     if(tmp)
       {
 	strcpy( cd->errmsg, "Error playing disc." );
 	cd->err = TRUE;
 
 	debug("cdrom.c: tcd_play_seconds error. CDROMPLAYMSF ioctl error.\n" );
+#ifdef TCD_BSD
+	ioctl( cd->cd_dev, CDIOCALLOW );
+#endif
     }
     cd->isplayable=TRUE;
     tcd_close_disc( cd );
@@ -562,7 +718,11 @@
     cd->err = FALSE;
 
     tcd_opencddev( cd, NULL );
+#ifdef TCD_BSD
+    if(!ioctl(cd->cd_dev, CDIOCEJECT))
+#else
     if(!ioctl(cd->cd_dev, CDROMEJECT))
+#endif
     {
 	cd->isplayable = FALSE;
 	strcpy(cd->errmsg, "No disc in drive ");
@@ -570,9 +730,17 @@
     } 
     else 
     {
+#ifdef TCD_BSD
+	tmp = ioctl( cd->cd_dev, CDIOCCLOSE );
+#else
 #ifdef CDROMCLOSETRAY
 	tmp = ioctl( cd->cd_dev, CDROMCLOSETRAY );
 #endif
+#endif
+
+#ifdef TCD_BSD
+	ioctl( cd->cd_dev, CDIOCPREVENT);
+#endif
 
 	if(tcd_post_init(cd))
 	{
@@ -582,6 +750,9 @@
 	    debug("cdrom.c: tcd_eject - disc init error. %s\n",  
 		  strerror(errno) );
 
+#ifdef TCD_BSD
+	    ioctl( cd->cd_dev, CDIOCALLOW);
+#endif
 	    return(-1);
 	}
 	cd->isplayable = TRUE;
@@ -600,12 +771,21 @@
     debug("cdrom.c: tcd_stopcd(%p)\n", cd );
 	
     /* SDH: Makes things cleaner on eject */
+#ifdef TCD_BSD
+    if( SC_AUDIOSTATUS(cd->sc)==CDROM_AUDIO_PAUSED )
+#else
     if( cd->sc.cdsc_audiostatus==CDROM_AUDIO_PAUSED )
+#endif
 	tcd_pausecd(cd);
 
     cd->err = FALSE;
     tcd_opencddev( cd, NULL );
+#ifdef TCD_BSD
+    ioctl( cd->cd_dev, CDIOCALLOW);
+    tmp = ioctl(cd->cd_dev, CDIOCSTOP);
+#else
     tmp = ioctl(cd->cd_dev, CDROMSTOP);
+#endif
     tcd_close_disc ( cd );
     if(tmp)
     {
@@ -626,13 +806,25 @@
     cd->err = FALSE;
 	
     tcd_opencddev( cd, NULL );
+#ifdef TCD_BSD
+    if(SC_AUDIOSTATUS(cd->sc)==CDROM_AUDIO_PAUSED)
+#else
     if(cd->sc.cdsc_audiostatus==CDROM_AUDIO_PAUSED)
+#endif
     {
+#ifdef TCD_BSD
+	tmp=ioctl(cd->cd_dev, CDIOCRESUME);
+#else
         tmp = ioctl(cd->cd_dev, CDROMRESUME);
+#endif
     }	        
     else
     {
+#ifdef TCD_BSD
+	tmp=ioctl(cd->cd_dev, CDIOCPAUSE);
+#else
         tmp=ioctl(cd->cd_dev, CDROMPAUSE);
+#endif
     }
     if(tmp < 0)
     {
@@ -647,6 +839,7 @@
 int tcd_change_disc( cd_struct *cd, int disc )
 {
 #ifdef TCD_CHANGER_ENABLED
+#ifndef TCD_BSD
     int tmp;
     cd->err = FALSE;
 
@@ -657,6 +850,7 @@
 	fprintf( stdout, "ioctl: %s\n", strerror(errno) );	
 
     return tmp;
+#endif
 #else
     debug("tcd_change_disc called, but changer support isn't compiled in. Ickyblah.\n" );
     return 0;
