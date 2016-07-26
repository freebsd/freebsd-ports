--- position.c.orig	1997-05-31 17:47:58 UTC
+++ position.c
@@ -40,7 +40,7 @@ struct AUDIO_HEADER tmp;
                         }
 
 	        bitrate=t_bitrate[tmp.ID][3-tmp.layer][tmp.bitrate_index];
-        	fs=t_sampling_frequency[tmp.ID][tmp.sampling_frequency];		
+        	fs=t_sampling_frequency[tmp.IDex][tmp.ID][tmp.sampling_frequency];		
 	        if (tmp.ID) mean_frame_size=144000*bitrate/fs;
 	        else mean_frame_size=72000*bitrate/fs;
 		fillbfr(mean_frame_size + tmp.padding_bit - hsize);
@@ -73,7 +73,7 @@ struct AUDIO_HEADER tmp;
 		 * so we have to go back one frame + 4 bytes + 1 byte (in case padding was used).
 		 */
 	        bitrate=t_bitrate[tmp.ID][3-tmp.layer][tmp.bitrate_index];
-        	fs=t_sampling_frequency[tmp.ID][tmp.sampling_frequency];		
+        	fs=t_sampling_frequency[tmp.IDex][tmp.ID][tmp.sampling_frequency];		
 	        if (tmp.ID) mean_frame_size=144000*bitrate/fs;
 	        else mean_frame_size=72000*bitrate/fs;
 
