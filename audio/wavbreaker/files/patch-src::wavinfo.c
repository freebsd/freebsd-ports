--- src/wavinfo.c.orig	Sat Dec 20 01:10:42 2003
+++ src/wavinfo.c	Sat Dec 20 01:11:23 2003
@@ -19,9 +19,10 @@
 	}
 
 	for (i = 1; i < argc; i++) {
+		SampleInfo sampleInfo;
+	
 		printf("Header info for: %s\n", argv[i]);
 
-		SampleInfo sampleInfo;
 		if (wav_read_header(argv[i], &sampleInfo, 1) != 0) {
 			printf(wav_get_error_message());
 		}
