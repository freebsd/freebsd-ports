--- source/cd_linux.cpp.orig	Fri Jan 23 14:59:01 2004
+++ source/cd_linux.cpp	Fri Jan 23 14:59:04 2004
@@ -32,7 +32,7 @@
 #include <fcntl.h>
 #include <time.h>
 #include <errno.h>
-#include <linux/cdrom.h>
+#include <sys/cdio.h>
 
 #include "gamedefs.h"
 #include "s_local.h"
@@ -137,7 +137,8 @@
 void CD_Update(void)
 {
 	guard(CD_Update);
-	struct cdrom_subchnl	subchnl;
+        struct ioc_read_subchannel	subchnl;
+        struct cd_sub_channel_info	data;	
 	static time_t			lastchk;
 
 	if (!cd_started)
@@ -149,15 +150,18 @@
 	if (playing && lastchk < time(NULL))
 	{
 		lastchk = time(NULL) + 2; //two seconds between chks
-		subchnl.cdsc_format = CDROM_MSF;
-		if (ioctl(cdfile, CDROMSUBCHNL, &subchnl) == -1 )
+                subchnl.data = &data;
+                subchnl.data_len = sizeof(data);
+                subchnl.address_format = CD_MSF_FORMAT;
+                subchnl.data_format = CD_CURRENT_POSITION;
+		if (ioctl(cdfile, CDIOCREADSUBCHANNEL, (char*) &subchnl) == -1 )
 		{
-			GCon->Log(NAME_Dev, "ioctl cdromsubchnl failed");
+			GCon->Log(NAME_Dev, "ioctl CDIOCREADSUBCHANNEL failed");
 			playing = false;
 			return;
 		}
-		if (subchnl.cdsc_audiostatus != CDROM_AUDIO_PLAY &&
-			subchnl.cdsc_audiostatus != CDROM_AUDIO_PAUSED)
+		if (subchnl.data->header.audio_status != CD_AS_PLAY_IN_PROGRESS &&
+			subchnl.data->header.audio_status != CD_AS_PLAY_PAUSED)
 		{
 			playing = false;
 			if (playLooping)
@@ -337,24 +341,24 @@
 
 static void CD_GetInfo(void)
 {
-	struct cdrom_tochdr		tochdr;
+        struct ioc_toc_header           tochdr;
 
 	cdValid = false;
 
-	if (ioctl(cdfile, CDROMREADTOCHDR, &tochdr) == -1)
+	if (ioctl(cdfile, CDIOREADTOCHEADER, &tochdr) == -1)
     {
-		GCon->Log(NAME_Dev, "ioctl cdromreadtochdr failed");
+		GCon->Log(NAME_Dev, "ioctl CDIOREADTOCHEADER failed");
 		return;
     }
 
-	if (tochdr.cdth_trk0 < 1)
+	if (tochdr.starting_track < 1)
 	{
 		GCon->Log(NAME_Dev, "CDAudio: no music tracks");
 		return;
 	}
 
 	cdValid = true;
-	maxTrack = tochdr.cdth_trk1;
+	maxTrack = tochdr.ending_track;
 }
 
 //==========================================================================
@@ -365,8 +369,8 @@
 
 static void CD_Play(int track, boolean looping)
 {
-	struct cdrom_tocentry	entry;
-	struct cdrom_ti			ti;
+        struct ioc_read_toc_single_entry        entry;
+        struct ioc_play_track                   ti;
 
 	if (!cdValid)
 	{
@@ -383,6 +387,7 @@
 		return;
 	}
 
+/*
 	// don't try to play a non-audio track
 	entry.cdte_track = track;
 	entry.cdte_format = CDROM_MSF;
@@ -396,7 +401,7 @@
 		GCon->Logf("CDAudio: track %d is not audio", track);
 		return;
 	}
-
+*/
 	if (playing)
 	{
 		if (playTrack == track)
@@ -404,19 +409,19 @@
 		CD_Stop();
 	}
 
-	ti.cdti_trk0 = track;
-	ti.cdti_trk1 = track;
-	ti.cdti_ind0 = 1;
-	ti.cdti_ind1 = 99;
+        ti.start_track = track;
+        ti.end_track = track;
+        ti.start_index = 1;
+        ti.end_index = 99;
 
-	if (ioctl(cdfile, CDROMPLAYTRKIND, &ti) == -1)
+	if (ioctl(cdfile, CDIOCPLAYTRACKS, &ti) == -1)
     {
-		GCon->Log(NAME_Dev, "ioctl cdromplaytrkind failed");
+		GCon->Log(NAME_Dev, "ioctl CDIOCPLAYTRACKS failed");
 		return;
     }
 
-	if (ioctl(cdfile, CDROMRESUME) == -1)
-		GCon->Log(NAME_Dev, "ioctl cdromresume failed");
+	if (ioctl(cdfile, CDIOCRESUME) == -1)
+		GCon->Log(NAME_Dev, "ioctl CDIOCRESUME failed");
 
 	playLooping = looping;
 	playTrack = track;
@@ -434,8 +439,8 @@
 	if (!playing)
 		return;
 
-	if (ioctl(cdfile, CDROMPAUSE) == -1)
-		GCon->Log(NAME_Dev, "ioctl cdrompause failed");
+	if (ioctl(cdfile, CDIOCPAUSE) == -1)
+		GCon->Log(NAME_Dev, "ioctl CDIOCPAUSE failed");
 
 	wasPlaying = playing;
 	playing = false;
@@ -452,8 +457,8 @@
 	if (!wasPlaying)
 		return;
 	
-	if (ioctl(cdfile, CDROMRESUME) == -1)
-		GCon->Log(NAME_Dev, "ioctl cdromresume failed");
+	if (ioctl(cdfile, CDIOCRESUME) == -1)
+		GCon->Log(NAME_Dev, "ioctl CDIOCRESUME failed");
 
 	playing = true;
 }
@@ -469,8 +474,8 @@
 	if (!playing)
 		return;
 
-	if (ioctl(cdfile, CDROMSTOP) == -1)
-		GCon->Log(NAME_Dev, "ioctl cdromstop failed");
+	if (ioctl(cdfile, CDIOCSTOP) == -1)
+		GCon->Log(NAME_Dev, "ioctl CDIOCSTOP failed");
 
 	wasPlaying = false;
 	playing = false;
@@ -484,8 +489,8 @@
 
 static void CD_OpenDoor(void)
 {
-	if (ioctl(cdfile, CDROMEJECT) == -1)
-		GCon->Log(NAME_Dev, "ioctl cdromeject failed");
+	if (ioctl(cdfile, CDIOCEJECT) == -1)
+		GCon->Log(NAME_Dev, "ioctl CDIOCEJECT failed");
 }
 
 //==========================================================================
@@ -496,8 +501,8 @@
 
 static void CD_CloseDoor(void)
 {
-	if (ioctl(cdfile, CDROMCLOSETRAY) == -1)
-		GCon->Log(NAME_Dev, "ioctl cdromclosetray failed");
+	if (ioctl(cdfile, CDIOCCLOSE) == -1)
+		GCon->Log(NAME_Dev, "ioctl CDIOCCLOSE failed");
 }
 
 //**************************************************************************
