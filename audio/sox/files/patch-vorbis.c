
$FreeBSD$

--- vorbis.c.orig	Thu Jan 17 01:11:39 2002
+++ vorbis.c	Thu Jan 17 01:13:07 2002
@@ -337,9 +337,8 @@
 	fprintf(stdout, "Channels: %d  Rate: %ld\n", ft->info.channels,
 		rate);
 
-	/* Set encoding to average bit rate of 128kbps with no min or max */
-	vorbis_encode_init(&ve->vi, ft->info.channels, ft->info.rate,
-			   -1, 128000, -1);
+	/* Set encoding to average bit rate of 112kbps VBR */
+	vorbis_encode_init_vbr(&ve->vi, ft->info.channels, ft->info.rate, 0.3f);
 
 	vorbis_analysis_init(&ve->vd, &ve->vi);
 	vorbis_block_init(&ve->vd, &ve->vb);
