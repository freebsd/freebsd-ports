--- ./cd_linux.c.orig	Thu Apr  6 20:23:18 2006
+++ ./cd_linux.c	Tue Aug 29 20:59:12 2006
@@ -30,7 +30,11 @@
 #include <string.h>
 #include <time.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#else
 #include <linux/cdrom.h>
+#endif
 
 #include "quakedef.h"
 #include "cdaudio.h"
@@ -54,8 +58,13 @@
 	if (cdfile == -1 || !enabled)
 		return; // no cd init'd
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCEJECT) == -1)
+		Com_DPrintf ("ioctl cdioceject failed\n");
+#else
 	if ( ioctl(cdfile, CDROMEJECT) == -1 ) 
 		Com_DPrintf ("ioctl cdromeject failed\n");
+#endif
 }
 
 
@@ -64,30 +73,53 @@
 	if (cdfile == -1 || !enabled)
 		return; // no cd init'd
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCCLOSE) == -1)
+		Com_DPrintf ("ioctl cdiocclose failed\n");
+#else
 	if ( ioctl(cdfile, CDROMCLOSETRAY) == -1 ) 
 		Com_DPrintf ("ioctl cdromclosetray failed\n");
+#endif
 }
 
 static int CDAudio_GetAudioDiskInfo(void)
 {
+#ifdef __FreeBSD__
+	struct ioc_toc_header tochdr;
+#else
 	struct cdrom_tochdr tochdr;
+#endif
 
 	cdValid = false;
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOREADTOCHEADER, &tochdr) == -1)
+	{
+		Com_DPrintf ("ioctl cdioreadtocheader failed\n");
+#else
 	if ( ioctl(cdfile, CDROMREADTOCHDR, &tochdr) == -1 ) 
     {
       Com_DPrintf ("ioctl cdromreadtochdr failed\n");
+#endif
 	  return -1;
     }
 
+#ifdef __FreeBSD__
+	if (tochdr.starting_track < 1)
+#else
 	if (tochdr.cdth_trk0 < 1)
+#endif
 	{
 		Com_DPrintf ("CDAudio: no music tracks\n");
 		return -1;
 	}
 
 	cdValid = true;
+#ifdef __FreeBSD__
+	maxTrack = tochdr.ending_track;
+#else
 	maxTrack = tochdr.cdth_trk1;
+#endif
 
 	return 0;
 }
@@ -95,8 +127,14 @@
 
 void CDAudio_Play(byte track, qbool looping)
 {
+#ifdef __FreeBSD__
+	struct ioc_read_toc_entry entry;
+	struct cd_toc_entry toc_buffer;
+	struct ioc_play_track ti;
+#else
 	struct cdrom_tocentry entry;
 	struct cdrom_ti ti;
+#endif
 
 	if (cdfile == -1 || !enabled)
 		return;
@@ -116,6 +154,21 @@
 		return;
 	}
 
+#ifdef __FreeBSD__
+	#define CDROM_DATA_TRACK 4
+	bzero((char *)&toc_buffer, sizeof(toc_buffer));
+	entry.data_len = sizeof(toc_buffer);
+	entry.data = &toc_buffer;
+	// don't try to play a non-audio track
+	entry.starting_track = track;
+	entry.address_format = CD_MSF_FORMAT;
+    if ( ioctl(cdfile, CDIOREADTOCENTRYS, &entry) == -1 )
+	{
+		Com_DPrintf("ioctl cdromreadtocentry failed\n");
+		return;
+	}
+	if (toc_buffer.control == CDROM_DATA_TRACK)
+#else
 	// don't try to play a non-audio track
 	entry.cdte_track = track;
 	entry.cdte_format = CDROM_MSF;
@@ -125,6 +178,7 @@
 		return;
 	}
 	if (entry.cdte_ctrl == CDROM_DATA_TRACK)
+#endif
 	{
 		Com_Printf ("CDAudio: track %i is not audio\n", track);
 		return;
@@ -137,19 +191,37 @@
 		CDAudio_Stop();
 	}
 
+#ifdef __FreeBSD__
+	ti.start_track = track;
+	ti.end_track = track;
+	ti.start_index = 1;
+	ti.end_index = 99;
+#else
 	ti.cdti_trk0 = track;
 	ti.cdti_trk1 = track;
 	ti.cdti_ind0 = 1;
 	ti.cdti_ind1 = 99;
+#endif
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCPLAYTRACKS, &ti) == -1)
+	{
+		Com_DPrintf ("ioctl cdiocplaytracks failed\n");
+#else
 	if ( ioctl(cdfile, CDROMPLAYTRKIND, &ti) == -1 ) 
     {
 		Com_DPrintf ("ioctl cdromplaytrkind failed\n");
+#endif
 		return;
     }
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCRESUME) == -1)
+		Com_DPrintf ("ioctl cdiocresume failed\n");
+#else
 	if ( ioctl(cdfile, CDROMRESUME) == -1 ) 
 		Com_DPrintf ("ioctl cdromresume failed\n");
+#endif
 
 	playLooping = looping;
 	playTrack = track;
@@ -168,8 +240,13 @@
 	if (!playing)
 		return;
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCSTOP) == -1)
+		Com_DPrintf ("ioctl cdiocstop failed (%d)\n", errno);
+#else
 	if ( ioctl(cdfile, CDROMSTOP) == -1 )
 		Com_DPrintf ("ioctl cdromstop failed (%d)\n", errno);
+#endif
 
 	wasPlaying = false;
 	playing = false;
@@ -183,8 +260,13 @@
 	if (!playing)
 		return;
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCPAUSE) == -1)
+		Com_DPrintf ("ioctl cdiocpause failed\n");
+#else
 	if ( ioctl(cdfile, CDROMPAUSE) == -1 ) 
 		Com_DPrintf ("ioctl cdrompause failed\n");
+#endif
 
 	wasPlaying = playing;
 	playing = false;
@@ -202,8 +284,13 @@
 	if (!wasPlaying)
 		return;
 	
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCRESUME) == -1)
+		Com_DPrintf ("ioctl cdiocresume failed\n");
+#else
 	if ( ioctl(cdfile, CDROMRESUME) == -1 ) 
 		Com_DPrintf ("ioctl cdromresume failed\n");
+#endif
 	playing = true;
 }
 
@@ -299,7 +386,12 @@
 
 void CDAudio_Update(void)
 {
+#ifdef __FreeBSD__
+	struct ioc_read_subchannel subchnl;
+	struct cd_sub_channel_info data;
+#else
 	struct cdrom_subchnl subchnl;
+#endif
 	static time_t lastchk;
 
 	if (!enabled)
@@ -323,6 +415,24 @@
 
 	if (playing && lastchk < time(NULL)) {
 		lastchk = time(NULL) + 2; //two seconds between chks
+#if defined(__FreeBSD__)
+		subchnl.address_format = CD_MSF_FORMAT;
+		subchnl.data_format = CD_CURRENT_POSITION;
+		subchnl.data_len = sizeof(data);
+		subchnl.track = playTrack;
+		subchnl.data = &data;
+		if (ioctl(cdfile, CDIOCREADSUBCHANNEL, &subchnl) == -1 ) {
+			Com_DPrintf("ioctl cdiocreadsubchannel failed\n");
+			playing = false;
+			return;
+		}
+		if (subchnl.data->header.audio_status != CD_AS_PLAY_IN_PROGRESS &&
+			subchnl.data->header.audio_status != CD_AS_PLAY_PAUSED) {
+			playing = false;
+			if (playLooping)
+				CDAudio_Play(playTrack, true);
+		}
+#else
 		subchnl.cdsc_format = CDROM_MSF;
 		if (ioctl(cdfile, CDROMSUBCHNL, &subchnl) == -1 ) {
 			Com_DPrintf ("ioctl cdromsubchnl failed\n");
@@ -335,6 +445,7 @@
 			if (playLooping)
 				CDAudio_Play(playTrack, true);
 		}
+#endif
 	}
 }
 
