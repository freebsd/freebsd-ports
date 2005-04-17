--- position.c	Sat May 31 14:47:58 1997
+++ position.c	Wed Apr 13 00:21:47 2005
@@ -40,7 +40,7 @@
                         }
 
 	        bitrate=t_bitrate[tmp.ID][3-tmp.layer][tmp.bitrate_index];
-        	fs=t_sampling_frequency[tmp.ID][tmp.sampling_frequency];		
+        	fs=t_sampling_frequency[tmp.IDex][tmp.ID][tmp.sampling_frequency];		
 	        if (tmp.ID) mean_frame_size=144000*bitrate/fs;
 	        else mean_frame_size=72000*bitrate/fs;
 		fillbfr(mean_frame_size + tmp.padding_bit - hsize);
@@ -73,7 +73,7 @@
 		 * so we have to go back one frame + 4 bytes + 1 byte (in case padding was used).
 		 */
 	        bitrate=t_bitrate[tmp.ID][3-tmp.layer][tmp.bitrate_index];
-        	fs=t_sampling_frequency[tmp.ID][tmp.sampling_frequency];		
+        	fs=t_sampling_frequency[tmp.IDex][tmp.ID][tmp.sampling_frequency];		
 	        if (tmp.ID) mean_frame_size=144000*bitrate/fs;
 	        else mean_frame_size=72000*bitrate/fs;
 
