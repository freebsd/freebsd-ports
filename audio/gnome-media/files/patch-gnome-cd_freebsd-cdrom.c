--- gnome-cd/freebsd-cdrom.c.orig	Sun Aug 22 00:42:31 2004
+++ gnome-cd/freebsd-cdrom.c	Sun Aug 22 00:48:36 2004
@@ -903,6 +903,11 @@
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
@@ -910,6 +915,11 @@
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
@@ -917,6 +927,11 @@
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
