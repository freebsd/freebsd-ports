--- layer2.c	Mon Jun 16 14:53:15 1997
+++ layer2.c	Wed Apr 13 00:21:47 2005
@@ -34,7 +34,7 @@
 	if (header->protection_bit==0) hsize+=2;
 
 	bitrate=t_bitrate[header->ID][3-header->layer][header->bitrate_index];
-        fs=t_sampling_frequency[header->ID][header->sampling_frequency];
+        fs=t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency];
         if (header->ID) mean_frame_size=144000*bitrate/fs;
         else mean_frame_size=72000*bitrate/fs;
 
