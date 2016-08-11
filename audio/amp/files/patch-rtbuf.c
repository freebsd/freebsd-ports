--- rtbuf.c.orig	1997-08-23 10:16:40 UTC
+++ rtbuf.c
@@ -337,15 +337,15 @@ int apar;
 			(mpegheader->mode != 3) ? "stereo" : "mono");
 		return -1;
 	}
-	apar = t_sampling_frequency[mpegheader->ID][mpegheader->sampling_frequency];
+	apar = t_sampling_frequency[mpegheader->IDex][mpegheader->ID][mpegheader->sampling_frequency];
 	if (ioctl(audio_fd, SNDCTL_DSP_SPEED, &apar) == -1) {
 		perror("ioctl: SNDCTL_DSP_SPEED");
 		return -1;
 	}
-	if (apar != t_sampling_frequency[mpegheader->ID][mpegheader->sampling_frequency]) {
+	if (apar != t_sampling_frequency[mpegheader->IDex][mpegheader->ID][mpegheader->sampling_frequency]) {
 		fprintf(stderr, "Warning: requested sampling rate %d does not "
 			"match effective %d\n", 
-			t_sampling_frequency[mpegheader->ID][mpegheader->sampling_frequency],
+			t_sampling_frequency[mpegheader->IDex][mpegheader->ID][mpegheader->sampling_frequency],
 			apar);
 	}
 
