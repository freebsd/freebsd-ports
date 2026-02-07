--- ./source/cd_linux.c.orig	Mon Dec 25 17:07:02 2006
+++ ./source/cd_linux.c	Mon Dec 25 17:07:03 2006
@@ -31,7 +31,11 @@
 #include <time.h>
 #include <errno.h>
 
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#else
 #include <linux/cdrom.h>
+#endif
 
 #include "client.h"
 
@@ -61,8 +65,13 @@
 	if (cdfile == -1 || !enabled)
 		return; // no cd init'd
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCEJECT) == -1)
+		Com_DPrintf ("ioctl cdioceject failed\n");
+#else
 	if ( ioctl(cdfile, CDROMEJECT) == -1 )
 		Com_DPrintf("ioctl cdromeject failed\n");
+#endif
 }
 
 
@@ -71,30 +80,53 @@
 	if (cdfile == -1 || !enabled)
 		return; // no cd init'd
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCCLOSE) == -1)
+		Com_DPrintf ("ioctl cdiocclose failed\n");
+#else
 	if ( ioctl(cdfile, CDROMCLOSETRAY) == -1 )
 		Com_DPrintf("ioctl cdromclosetray failed\n");
+#endif
 }
 
 static int CDAudio_GetAudioDiskInfo(void)
 {
+#ifdef __FreeBSD__
+	struct ioc_toc_header tochdr;
+#else
 	struct cdrom_tochdr tochdr;
+#endif
 
 	cdValid = qfalse;
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOREADTOCHEADER, &tochdr) == -1)
+	{
+		Com_DPrintf ("ioctl cdioreadtocheader failed\n");
+#else
 	if ( ioctl(cdfile, CDROMREADTOCHDR, &tochdr) == -1 )
     {
       Com_DPrintf("ioctl cdromreadtochdr failed\n");
+#endif
 	  return -1;
     }
 
+#ifdef __FreeBSD__
+	if (tochdr.starting_track < 1)
+#else
 	if (tochdr.cdth_trk0 < 1)
+#endif
 	{
 		Com_DPrintf("CDAudio: no music tracks\n");
 		return -1;
 	}
 
 	cdValid = qtrue;
+#ifdef __FreeBSD__
+	maxTrack = tochdr.ending_track;
+#else
 	maxTrack = tochdr.cdth_trk1;
+#endif
 
 	return 0;
 }
@@ -102,8 +134,14 @@
 
 void CDAudio_Play(int track, qboolean looping)
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
@@ -123,6 +161,21 @@
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
@@ -132,6 +185,7 @@
 		return;
 	}
 	if (entry.cdte_ctrl == CDROM_DATA_TRACK)
+#endif
 	{
 		Com_Printf("CDAudio: track %i is not audio\n", track);
 		return;
@@ -144,19 +198,37 @@
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
 		Com_DPrintf("ioctl cdromplaytrkind failed\n");
+#endif
 		return;
     }
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCRESUME) == -1)
+		Com_DPrintf ("ioctl cdiocresume failed\n");
+#else
 	if ( ioctl(cdfile, CDROMRESUME) == -1 )
 		Com_DPrintf("ioctl cdromresume failed\n");
+#endif
 
 	playLooping = looping;
 	playTrack = track;
@@ -175,8 +247,13 @@
 	if (!playing)
 		return;
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCSTOP) == -1)
+		Com_DPrintf ("ioctl cdiocstop failed (%d)\n", errno);
+#else
 	if ( ioctl(cdfile, CDROMSTOP) == -1 )
 		Com_DPrintf("ioctl cdromstop failed (%d)\n", errno);
+#endif
 
 	wasPlaying = qfalse;
 	playing = qfalse;
@@ -190,8 +267,13 @@
 	if (!playing)
 		return;
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCPAUSE) == -1)
+		Com_DPrintf ("ioctl cdiocpause failed\n");
+#else
 	if ( ioctl(cdfile, CDROMPAUSE) == -1 )
 		Com_DPrintf("ioctl cdrompause failed\n");
+#endif
 
 	wasPlaying = playing;
 	playing = qfalse;
@@ -209,8 +291,13 @@
 	if (!wasPlaying)
 		return;
 
+#ifdef __FreeBSD__
+	if (ioctl(cdfile, CDIOCRESUME) == -1)
+		Com_DPrintf ("ioctl cdiocresume failed\n");
+#else
 	if ( ioctl(cdfile, CDROMRESUME) == -1 )
 		Com_DPrintf("ioctl cdromresume failed\n");
+#endif
 	playing = qtrue;
 }
 
@@ -334,7 +421,12 @@
 
 void CDAudio_Update(void)
 {
+#ifdef __FreeBSD__
+	struct ioc_read_subchannel subchnl;
+	struct cd_sub_channel_info data;
+#else
 	struct cdrom_subchnl subchnl;
+#endif
 	static time_t lastchk;
 
 	if (cdfile == -1 || !enabled)
@@ -357,6 +449,24 @@
 	}
 
 	if (playing && lastchk < time(NULL)) {
+#if defined(__FreeBSD__)
+		subchnl.address_format = CD_MSF_FORMAT;
+		subchnl.data_format = CD_CURRENT_POSITION;
+		subchnl.data_len = sizeof(data);
+		subchnl.track = playTrack;
+		subchnl.data = &data;
+		if (ioctl(cdfile, CDIOCREADSUBCHANNEL, &subchnl) == -1 ) {
+			Com_DPrintf("ioctl cdiocreadsubchannel failed\n");
+			playing = qfalse;
+			return;
+		}
+		if (subchnl.data->header.audio_status != CD_AS_PLAY_IN_PROGRESS &&
+			subchnl.data->header.audio_status != CD_AS_PLAY_PAUSED) {
+			playing = qfalse;
+			if (playLooping)
+				CDAudio_Play(playTrack, qtrue);
+		}
+#else
 		lastchk = time(NULL) + 2; //two seconds between chks
 		subchnl.cdsc_format = CDROM_MSF;
 		if (ioctl(cdfile, CDROMSUBCHNL, &subchnl) == -1 ) {
@@ -370,6 +480,7 @@
 			if (playLooping)
 				CDAudio_Play(playTrack, qtrue);
 		}
+#endif
 	}
 }
 
