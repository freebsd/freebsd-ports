--- cd_linux.c.orig	Sun Mar 14 12:11:16 2004
+++ cd_linux.c	Sun Mar 14 12:24:07 2004
@@ -31,7 +31,7 @@
 #include <time.h>
 #include <errno.h>
 
-#include <linux/cdrom.h>
+#include <sys/cdio.h>
 
 #include "quakedef.h"
 
@@ -54,8 +54,8 @@
 	if (cdfile == -1 || !enabled)
 		return; // no cd init'd
 
-	if ( ioctl(cdfile, CDROMEJECT) == -1 ) 
-		Con_DPrintf("ioctl cdromeject failed\n");
+	if ( ioctl(cdfile, CDIOCEJECT) == -1 ) 
+		Con_DPrintf("ioctl CDIOCEJECT failed\n");
 }
 
 
@@ -64,30 +64,30 @@
 	if (cdfile == -1 || !enabled)
 		return; // no cd init'd
 
-	if ( ioctl(cdfile, CDROMCLOSETRAY) == -1 ) 
-		Con_DPrintf("ioctl cdromclosetray failed\n");
+	if ( ioctl(cdfile, CDIOCCLOSE) == -1 ) 
+		Con_DPrintf("ioctl CDIOCCLOSE failed\n");
 }
 
 static int CDAudio_GetAudioDiskInfo(void)
 {
-	struct cdrom_tochdr tochdr;
+	struct ioc_toc_header tochdr;
 
 	cdValid = false;
 
-	if ( ioctl(cdfile, CDROMREADTOCHDR, &tochdr) == -1 ) 
+	if ( ioctl(cdfile, CDIOREADTOCHEADER, &tochdr) == -1 ) 
     {
-      Con_DPrintf("ioctl cdromreadtochdr failed\n");
+      Con_DPrintf("ioctl CDIOREADTOCHEADER failed\n");
 	  return -1;
     }
 
-	if (tochdr.cdth_trk0 < 1)
+	if (tochdr.starting_track < 1)
 	{
 		Con_DPrintf("CDAudio: no music tracks\n");
 		return -1;
 	}
 
 	cdValid = true;
-	maxTrack = tochdr.cdth_trk1;
+	maxTrack = tochdr.ending_track;
 
 	return 0;
 }
@@ -95,8 +95,8 @@
 
 void CDAudio_Play(byte track, qboolean looping)
 {
-	struct cdrom_tocentry entry;
-	struct cdrom_ti ti;
+        struct ioc_read_toc_single_entry entry;
+        struct ioc_play_track ti;
 
 	if (cdfile == -1 || !enabled)
 		return;
@@ -115,7 +115,7 @@
 		Con_DPrintf("CDAudio: Bad track number %u.\n", track);
 		return;
 	}
-
+/*
 	// don't try to play a non-audio track
 	entry.cdte_track = track;
 	entry.cdte_format = CDROM_MSF;
@@ -129,7 +129,7 @@
 		Con_Printf("CDAudio: track %i is not audio\n", track);
 		return;
 	}
-
+*/
 	if (playing)
 	{
 		if (playTrack == track)
@@ -137,19 +137,19 @@
 		CDAudio_Stop();
 	}
 
-	ti.cdti_trk0 = track;
-	ti.cdti_trk1 = track;
-	ti.cdti_ind0 = 1;
-	ti.cdti_ind1 = 99;
-
-	if ( ioctl(cdfile, CDROMPLAYTRKIND, &ti) == -1 ) 
+        ti.start_track = track;
+        ti.end_track = track;
+        ti.start_index = 1;
+        ti.end_index = 99;
+        
+	if ( ioctl(cdfile, CDIOCPLAYTRACKS, &ti) == -1 ) 
     {
-		Con_DPrintf("ioctl cdromplaytrkind failed\n");
+		Con_DPrintf("ioctl CDIOCPLAYTRACKS failed\n");
 		return;
     }
 
-	if ( ioctl(cdfile, CDROMRESUME) == -1 ) 
-		Con_DPrintf("ioctl cdromresume failed\n");
+	if ( ioctl(cdfile, CDIOCRESUME) == -1 ) 
+		Con_DPrintf("ioctl CDIOCRESUME failed\n");
 
 	playLooping = looping;
 	playTrack = track;
@@ -168,8 +168,8 @@
 	if (!playing)
 		return;
 
-	if ( ioctl(cdfile, CDROMSTOP) == -1 )
-		Con_DPrintf("ioctl cdromstop failed (%d)\n", errno);
+	if ( ioctl(cdfile, CDIOCSTOP) == -1 )
+		Con_DPrintf("ioctl CDIOCSTOP failed (%d)\n", errno);
 
 	wasPlaying = false;
 	playing = false;
@@ -183,8 +183,8 @@
 	if (!playing)
 		return;
 
-	if ( ioctl(cdfile, CDROMPAUSE) == -1 ) 
-		Con_DPrintf("ioctl cdrompause failed\n");
+	if ( ioctl(cdfile, CDIOCPAUSE) == -1 ) 
+		Con_DPrintf("ioctl CDIOCPAUSE failed\n");
 
 	wasPlaying = playing;
 	playing = false;
@@ -202,8 +202,8 @@
 	if (!wasPlaying)
 		return;
 	
-	if ( ioctl(cdfile, CDROMRESUME) == -1 ) 
-		Con_DPrintf("ioctl cdromresume failed\n");
+	if ( ioctl(cdfile, CDIOCRESUME) == -1 ) 
+		Con_DPrintf("ioctl CDIOCRESUME failed\n");
 	playing = true;
 }
 
@@ -327,7 +327,8 @@
 
 void CDAudio_Update(void)
 {
-	struct cdrom_subchnl subchnl;
+        struct ioc_read_subchannel subchnl;
+        struct cd_sub_channel_info data;
 	static time_t lastchk;
 
 	if (!enabled)
@@ -351,14 +352,17 @@
 
 	if (playing && lastchk < time(NULL)) {
 		lastchk = time(NULL) + 2; //two seconds between chks
-		subchnl.cdsc_format = CDROM_MSF;
-		if (ioctl(cdfile, CDROMSUBCHNL, &subchnl) == -1 ) {
-			Con_DPrintf("ioctl cdromsubchnl failed\n");
+                subchnl.data = &data;
+                subchnl.data_len = sizeof(data);
+                subchnl.address_format = CD_MSF_FORMAT;
+                subchnl.data_format = CD_CURRENT_POSITION;
+		if (ioctl(cdfile, CDIOCREADSUBCHANNEL, (char*) &subchnl) == -1 ) {
+			Con_DPrintf("ioctl CDIOCREADSUBCHANNEL failed\n");
 			playing = false;
 			return;
 		}
-		if (subchnl.cdsc_audiostatus != CDROM_AUDIO_PLAY &&
-			subchnl.cdsc_audiostatus != CDROM_AUDIO_PAUSED) {
+		if (subchnl.data->header.audio_status != CD_AS_PLAY_IN_PROGRESS &&
+			subchnl.data->header.audio_status != CD_AS_PLAY_PAUSED) {
 			playing = false;
 			if (playLooping)
 				CDAudio_Play(playTrack, true);
