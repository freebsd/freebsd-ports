--- audio.c	Sat Aug 23 08:30:21 1997
+++ audio.c	Wed Apr 13 00:22:25 2005
@@ -56,7 +56,7 @@
 		msg("{ %d } ",frameNo);
 	}
 	if (A_SHOW_TIME && !(frameNo%10)) {
-		seconds=frameNo*1152/t_sampling_frequency[header->ID][header->sampling_frequency];
+		seconds=frameNo*(header->ID==0?576:1152)/t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency];
 		minutes=seconds/60;
 		seconds=seconds % 60;
 		msg("[%d:%02d]",minutes,seconds);
@@ -245,10 +245,6 @@
 	switch (err) {
 		case GETHDR_ERR: die("error reading mpeg bitstream. exiting.\n");
 					break;
-		case GETHDR_NS : warn("this is a file in MPEG 2.5 format, which is not defined\n");
-				 warn("by ISO/MPEG. It is \"a special Fraunhofer format\".\n");
-				 warn("amp does not support this format. sorry.\n");
-					break;
 		case GETHDR_FL1: warn("ISO/MPEG layer 1 is not supported by amp (yet).\n");
 					break;
 		case GETHDR_FF : warn("free format bitstreams are not supported. sorry.\n");
@@ -268,10 +264,10 @@
 {
 	if (A_AUDIO_PLAY)  
 		if (AUDIO_BUFFER_SIZE==0)
-			audioOpen(t_sampling_frequency[header->ID][header->sampling_frequency],
+			audioOpen(t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency],
 					(header->mode!=3 && !A_DOWNMIX),A_SET_VOLUME);
 		else
-			audioBufferOpen(t_sampling_frequency[header->ID][header->sampling_frequency],
+			audioBufferOpen(t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency],
 					(header->mode!=3 && !A_DOWNMIX),A_SET_VOLUME);
 	return 0;
 }
