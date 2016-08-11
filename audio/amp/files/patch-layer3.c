--- layer3.c.orig	1997-08-18 12:42:17 UTC
+++ layer3.c
@@ -61,7 +61,7 @@ int mean_frame_size,bitrate,fs,hsize,ssi
 /* MPEG2 only has one granule
 */
 	bitrate=t_bitrate[header->ID][3-header->layer][header->bitrate_index];
-	fs=t_sampling_frequency[header->ID][header->sampling_frequency];
+	fs=t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency];
         if (header->ID) mean_frame_size=144000*bitrate/fs;
         else mean_frame_size=72000*bitrate/fs;
 
@@ -96,8 +96,8 @@ int mean_frame_size,bitrate,fs,hsize,ssi
 
 /* these two should go away
 */
-	t_l=&t_b8_l[header->ID][header->sampling_frequency][0];
-	t_s=&t_b8_s[header->ID][header->sampling_frequency][0];
+	t_l=&t_b8_l[header->IDex][header->ID][header->sampling_frequency][0];
+	t_s=&t_b8_s[header->IDex][header->ID][header->sampling_frequency][0];
 
 /* debug/dump stuff
 */
