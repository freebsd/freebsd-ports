--- ./common/cd_linux.c.orig	Tue Dec 27 23:50:49 2005
+++ ./common/cd_linux.c	Sun May 14 16:20:57 2006
@@ -31,7 +31,11 @@
 #include <time.h>
 #include <errno.h>
 
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#else
 #include <linux/cdrom.h>
+#endif
 #include <paths.h>
 
 #include "cdaudio.h"
@@ -57,8 +61,13 @@
 
 static int cdfile = -1;
 static char cd_dev[64] = _PATH_DEV "cdrom";
+#ifdef __FreeBSD__
+static struct ioc_vol drv_vol_saved;
+static struct ioc_vol drv_vol;
+#else
 static struct cdrom_volctrl drv_vol_saved;
 static struct cdrom_volctrl drv_vol;
+#endif
 
 static void
 CDAudio_Eject(void)
@@ -66,8 +75,13 @@
     if (cdfile == -1 || !enabled)
 	return;			// no cd init'd
 
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCEJECT) == -1)
+	Con_DPrintf ("ioctl cdioceject failed\n");
+#else
     if (ioctl(cdfile, CDROMEJECT) == -1)
 	Con_DPrintf("ioctl cdromeject failed\n");
+#endif
 }
 
 
@@ -77,29 +91,51 @@
     if (cdfile == -1 || !enabled)
 	return;			// no cd init'd
 
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCCLOSE) == -1)
+	Con_DPrintf ("ioctl cdiocclose failed\n");
+#else
     if (ioctl(cdfile, CDROMCLOSETRAY) == -1)
 	Con_DPrintf("ioctl cdromclosetray failed\n");
+#endif
 }
 
 static int
 CDAudio_GetAudioDiskInfo(void)
 {
+#ifdef __FreeBSD__
+	struct ioc_toc_header tochdr;
+#else
     struct cdrom_tochdr tochdr;
+#endif
 
     cdValid = false;
 
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOREADTOCHEADER, &tochdr) == -1) {
+	Con_DPrintf ("ioctl cdioreadtocheader failed\n");
+#else
     if (ioctl(cdfile, CDROMREADTOCHDR, &tochdr) == -1) {
 	Con_DPrintf("ioctl cdromreadtochdr failed\n");
+#endif
 	return -1;
     }
 
+#ifdef __FreeBSD__
+    if (tochdr.starting_track < 1) {
+#else
     if (tochdr.cdth_trk0 < 1) {
+#endif
 	Con_DPrintf("CDAudio: no music tracks\n");
 	return -1;
     }
 
     cdValid = true;
+#ifdef __FreeBSD__
+    maxTrack = tochdr.ending_track;
+#else
     maxTrack = tochdr.cdth_trk1;
+#endif
 
     return 0;
 }
@@ -108,8 +144,14 @@
 void
 CDAudio_Play(byte track, qboolean looping)
 {
+#ifdef __FreeBSD__
+    struct ioc_read_toc_entry entry;
+    struct cd_toc_entry toc_buffer;
+    struct ioc_play_track ti;
+#else
     struct cdrom_tocentry entry;
     struct cdrom_ti ti;
+#endif
 
     if (cdfile == -1 || !enabled)
 	return;
@@ -126,6 +168,20 @@
 	Con_DPrintf("CDAudio: Bad track number %u.\n", track);
 	return;
     }
+#ifdef __FreeBSD__
+    #define CDROM_DATA_TRACK 4
+    bzero((char *)&toc_buffer, sizeof(toc_buffer));
+    entry.data_len = sizeof(toc_buffer);
+    entry.data = &toc_buffer;
+    // don't try to play a non-audio track
+    entry.starting_track = track;
+    entry.address_format = CD_MSF_FORMAT;
+    if ( ioctl(cdfile, CDIOREADTOCENTRYS, &entry) == -1 ) {
+	Con_DPrintf("ioctl cdromreadtocentry failed\n");
+	return;
+    }
+    if (toc_buffer.control == CDROM_DATA_TRACK) {
+#else
     // don't try to play a non-audio track
     entry.cdte_track = track;
     entry.cdte_format = CDROM_MSF;
@@ -134,6 +190,7 @@
 	return;
     }
     if (entry.cdte_ctrl == CDROM_DATA_TRACK) {
+#endif
 	Con_Printf("CDAudio: track %i is not audio\n", track);
 	return;
     }
@@ -144,18 +201,35 @@
 	CDAudio_Stop();
     }
 
+#ifdef __FreeBSD__
+    ti.start_track = track;
+    ti.end_track = track;
+    ti.start_index = 1;
+    ti.end_index = 99;
+#else
     ti.cdti_trk0 = track;
     ti.cdti_trk1 = track;
     ti.cdti_ind0 = 1;
     ti.cdti_ind1 = 99;
+#endif
 
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCPLAYTRACKS, &ti) == -1) {
+	Con_DPrintf ("ioctl cdiocplaytracks failed\n");
+#else
     if (ioctl(cdfile, CDROMPLAYTRKIND, &ti) == -1) {
 	Con_DPrintf("ioctl cdromplaytrkind failed\n");
+#endif
 	return;
     }
 
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCRESUME) == -1)
+	Con_DPrintf ("ioctl cdiocresume failed\n");
+#else
     if (ioctl(cdfile, CDROMRESUME) == -1)
 	Con_DPrintf("ioctl cdromresume failed\n");
+#endif
 
     playLooping = looping;
     playTrack = track;
@@ -172,8 +246,13 @@
     if (!playing)
 	return;
 
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCSTOP) == -1)
+	Con_DPrintf ("ioctl cdiocstop failed (%d)\n", errno);
+#else
     if (ioctl(cdfile, CDROMSTOP) == -1)
 	Con_DPrintf("ioctl cdromstop failed (%d)\n", errno);
+#endif
 
     wasPlaying = false;
     playing = false;
@@ -188,8 +267,13 @@
     if (!playing)
 	return;
 
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCPAUSE) == -1)
+	Con_DPrintf ("ioctl cdiocpause failed\n");
+#else
     if (ioctl(cdfile, CDROMPAUSE) == -1)
 	Con_DPrintf("ioctl cdrompause failed\n");
+#endif
 
     wasPlaying = playing;
     playing = false;
@@ -208,8 +292,13 @@
     if (!wasPlaying)
 	return;
 
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCRESUME) == -1)
+	Con_DPrintf ("ioctl cdiocresume failed\n");
+#else
     if (ioctl(cdfile, CDROMRESUME) == -1)
 	Con_DPrintf("ioctl cdromresume failed\n");
+#endif
     playing = true;
 }
 
@@ -322,26 +411,60 @@
 void
 CDAudio_Update(void)
 {
+#ifdef __FreeBSD__
+    struct ioc_read_subchannel subchnl;
+    struct cd_sub_channel_info data;
+#else
     struct cdrom_subchnl subchnl;
+#endif
     static time_t lastchk;
 
     if (!enabled)
 	return;
 
+#ifdef __FreeBSD__
+    if ((int)(255.0 * bgmvolume.value) != (int)drv_vol.vol[0]) {
+#else
     if ((int)(255.0 * bgmvolume.value) != (int)drv_vol.channel0) {
+#endif
 	if (bgmvolume.value > 1.0f)
 	    Cvar_SetValue ("bgmvolume", 1.0f);
 	if (bgmvolume.value < 0.0f)
 	    Cvar_SetValue ("bgmvolume", 0.0f);
 
+#ifdef __FreeBSD__
+	drv_vol.vol[0] = drv_vol.vol[2] =
+	    drv_vol.vol[1] = drv_vol.vol[3] = bgmvolume.value * 255.0;
+	if (ioctl(cdfile, CDIOCSETVOL, &drv_vol) == -1 )
+	    Con_DPrintf("ioctl CDIOCSETVOL failed\n");
+#else
 	drv_vol.channel0 = drv_vol.channel2 =
 	    drv_vol.channel1 = drv_vol.channel3 = bgmvolume.value * 255.0;
 	if (ioctl(cdfile, CDROMVOLCTRL, &drv_vol) == -1 )
 	    Con_DPrintf("ioctl CDROMVOLCTRL failed\n");
+#endif
     }
 
     if (playing && lastchk < time(NULL)) {
 	lastchk = time(NULL) + 2;	//two seconds between chks
+#if defined(__FreeBSD__)
+	subchnl.address_format = CD_MSF_FORMAT;
+	subchnl.data_format = CD_CURRENT_POSITION;
+	subchnl.data_len = sizeof(data);
+	subchnl.track = playTrack;
+	subchnl.data = &data;
+	if (ioctl(cdfile, CDIOCREADSUBCHANNEL, &subchnl) == -1 ) {
+	    Con_DPrintf("ioctl cdiocreadsubchannel failed\n");
+	    playing = false;
+	    return;
+	}
+	if (subchnl.data->header.audio_status != CD_AS_PLAY_IN_PROGRESS &&
+	    subchnl.data->header.audio_status != CD_AS_PLAY_PAUSED) {
+	    playing = false;
+	    if (playLooping)
+		CDAudio_Play(playTrack, true);
+	}
+#else
 	subchnl.cdsc_format = CDROM_MSF;
 	if (ioctl(cdfile, CDROMSUBCHNL, &subchnl) == -1) {
 	    Con_DPrintf("ioctl cdromsubchnl failed\n");
@@ -354,6 +477,7 @@
 	    if (playLooping)
 		CDAudio_Play(playTrack, true);
 	}
+#endif
     }
 }
 
@@ -398,16 +522,31 @@
     Cmd_AddCommand("cd", CD_f);
 
     /* get drive's current volume */
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCGETVOL, &drv_vol_saved) == -1) {
+	Con_DPrintf("ioctl CDIOCGETVOL failed\n");
+	drv_vol_saved.vol[0] = drv_vol_saved.vol[2] =
+	    drv_vol_saved.vol[1] = drv_vol_saved.vol[3] = 255.0;
+    }
+#else
     if (ioctl(cdfile, CDROMVOLREAD, &drv_vol_saved) == -1) {
 	Con_DPrintf("ioctl CDROMVOLREAD failed\n");
 	drv_vol_saved.channel0 = drv_vol_saved.channel2 =
 	    drv_vol_saved.channel1 = drv_vol_saved.channel3 = 255.0;
     }
+#endif
     /* set our own volume */
+#ifdef __FreeBSD__
+    drv_vol.vol[0] = drv_vol.vol[2] =
+	drv_vol.vol[1] = drv_vol.vol[2] = bgmvolume.value * 255.0;
+    if (ioctl(cdfile, CDIOCSETVOL, &drv_vol) == -1)
+	Con_Printf("ioctl CDIOCSETVOL failed\n");
+#else
     drv_vol.channel0 = drv_vol.channel2 =
 	drv_vol.channel1 = drv_vol.channel3 = bgmvolume.value * 255.0;
     if (ioctl(cdfile, CDROMVOLCTRL, &drv_vol) == -1)
 	Con_Printf("ioctl CDROMVOLCTRL failed\n");
+#endif
 
     return 0;
 }
@@ -421,8 +560,13 @@
     CDAudio_Stop();
 
     /* Restore the saved volume setting */
+#ifdef __FreeBSD__
+    if (ioctl(cdfile, CDIOCSETVOL, &drv_vol_saved) == -1)
+	Con_DPrintf("ioctl CDIOCSETVOL failed\n");
+#else
     if (ioctl(cdfile, CDROMVOLCTRL, &drv_vol_saved) == -1)
 	Con_DPrintf("ioctl CDROMVOLCTRL failed\n");
+#endif
 
     close(cdfile);
     cdfile = -1;
