--- Sources/Sound/Sound/ClanSound/cdaudio_linux.cpp.orig	Thu Jan 22 13:48:18 2004
+++ Sources/Sound/Sound/ClanSound/cdaudio_linux.cpp	Thu Jan 22 14:02:41 2004
@@ -293,7 +293,7 @@
 {
 	#ifdef __FreeBSD__
 	ioc_read_subchannel sub_channel; 
-	cd_sub_channel_header subinfo;
+	cd_sub_channel_info subinfo;
 
 	sub_channel.data_len = sizeof(subinfo);
 	sub_channel.data = &subinfo;	
@@ -310,7 +310,7 @@
 #ifdef __FreeBSD__
 	if(!ioctl(file_handle,CDIOCREADSUBCHANNEL, &sub_channel))
 	{
-		if(subinfo.audio_status == CD_AS_PLAY_IN_PROGRESS)
+		if(subinfo.header.audio_status == CD_AS_PLAY_IN_PROGRESS)
 			return true;
 		else
 			return false;
@@ -562,8 +562,8 @@
 	        return false;
 	    
 #ifdef __FreeBSD__
-			track.start_lba = cur_track_info.entry.addr.lba
-			track.track_length = next_track_info.entry.data_len;
+	    track.start_lba = cur_track_info.entry.addr.lba;
+	    track.track_length = next_track_info.entry.addr.lba - cur_track_info.entry.addr.lba;
 #else
 	    track.start_lba = cur_track_info.cdte_addr.lba;
 	    track.track_length = next_track_info.cdte_addr.lba - cur_track_info.cdte_addr.lba;
