--- layer2.c.orig	1997-06-16 17:53:15 UTC
+++ layer2.c
@@ -34,7 +34,7 @@ int hsize,fs,mean_frame_size;
 	if (header->protection_bit==0) hsize+=2;
 
 	bitrate=t_bitrate[header->ID][3-header->layer][header->bitrate_index];
-        fs=t_sampling_frequency[header->ID][header->sampling_frequency];
+        fs=t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency];
         if (header->ID) mean_frame_size=144000*bitrate/fs;
         else mean_frame_size=72000*bitrate/fs;
 
