--- gnome-cd/freebsd-cdrom.c.orig	Mon Jan  5 23:12:49 2004
+++ gnome-cd/freebsd-cdrom.c	Sun Aug 22 01:06:01 2004
@@ -896,6 +896,8 @@
 
 	ASSIGN_MSF (realstatus->relative, blank_msf);
 	ASSIGN_MSF (realstatus->absolute, blank_msf);
+	ASSIGN_MSF (realstatus->length, blank_msf);
+
 	realstatus->track = 1;
 	switch (subchnl.data->header.audio_status) {
 	case CD_AS_PLAY_IN_PROGRESS:
@@ -903,6 +905,11 @@
 		ASSIGN_MSF (realstatus->relative, subchnl.data->what.position.reladdr.msf);
 		ASSIGN_MSF (realstatus->absolute, subchnl.data->what.position.absaddr.msf);
 		realstatus->track = subchnl.data->what.position.track_number;
+		if(priv && realstatus->track>0 &&
+		   realstatus->track<=priv->number_tracks){
+			/* track_info may not be initialized */
+			ASSIGN_MSF (realstatus->length, priv->track_info[realstatus->track-1].length);
+		}
 		break;
 
 	case CD_AS_PLAY_PAUSED:
@@ -910,6 +917,11 @@
 		ASSIGN_MSF (realstatus->relative, subchnl.data->what.position.reladdr.msf);
 		ASSIGN_MSF (realstatus->absolute, subchnl.data->what.position.absaddr.msf);
 		realstatus->track = subchnl.data->what.position.track_number;
+		if(priv && realstatus->track>0 &&
+		   realstatus->track<=priv->number_tracks){
+			/* track_info may not be initialized */
+			ASSIGN_MSF (realstatus->length, priv->track_info[realstatus->track-1].length);
+		}
 		break;
 
 	case CD_AS_PLAY_COMPLETED:
@@ -917,6 +929,11 @@
 		ASSIGN_MSF (realstatus->relative, subchnl.data->what.position.reladdr.msf);
 		ASSIGN_MSF (realstatus->absolute, subchnl.data->what.position.absaddr.msf);
 		realstatus->track = subchnl.data->what.position.track_number;
+		if(priv && realstatus->track>0 &&
+		   realstatus->track<=priv->number_tracks){
+			/* track_info may not be initialized */
+			ASSIGN_MSF (realstatus->length, priv->track_info[realstatus->track-1].length);
+		}
 		break;
 
 	case CD_AS_AUDIO_INVALID:
