--- otherlibs/highgui/cvcap_ffmpeg.cpp.bak	2009-07-25 15:45:10.000000000 +0200
+++ otherlibs/highgui/cvcap_ffmpeg.cpp	2009-07-25 15:48:41.000000000 +0200
@@ -801,7 +801,11 @@
 
 	if (!(mywriter->fmt->flags & AVFMT_NOFILE)) {
 		/* close the output file */
+#if LIBAVFORMAT_BUILD > 4628
+		url_fclose(mywriter->oc->pb);
+#else
 		url_fclose(&mywriter->oc->pb);
+#endif
 	}
 
 	/* free the stream */
