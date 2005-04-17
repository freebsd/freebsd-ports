--- dump.c	Sat May 31 17:19:38 1997
+++ dump.c	Wed Apr 13 00:21:47 2005
@@ -46,19 +46,21 @@
 void show_header(struct AUDIO_HEADER *header)
 {
 int bitrate=t_bitrate[header->ID][3-header->layer][header->bitrate_index];
-int fs=t_sampling_frequency[header->ID][header->sampling_frequency];
-int mpg,layer;
+int fs=t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency];
+int mpg,mpg_ex,layer;
 char stm[8];
 	if (A_QUIET) return;
 	layer=4-header->layer;
 	if (header->ID==1) mpg=1;
 	else mpg=2;
+	if (header->IDex==1) mpg_ex=0;
+	else mpg_ex=5;
 	if (header->mode==3) strcpy(stm,"mono");
 	else strcpy(stm,"stereo");
 
 	printf("\n\
 Properties:    %s %dHz\n\
-Coding Method: MPEG%1d.0 layer%1d\n\
+Coding Method: MPEG%1d.%1d layer%1d\n\
 Bitrate:       %dkbit/s\n"\
-		,stm,fs,mpg,layer,bitrate);
+		,stm,fs,mpg,mpg_ex,layer,bitrate);
 }
