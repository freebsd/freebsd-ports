--- quisk.h.orig	2022-11-01 15:26:26 UTC
+++ quisk.h
@@ -10,7 +10,7 @@
 #define MAX_FILTER_SIZE		10001
 #define BIG_VOLUME		2.2e9
 #define CLOSED_TEXT		"The sound device is closed."
-#define CLIP32			2147483647
+#define CLIP32			(float)2147483647
 #define CLIP16			32767
 #define SAMP_BUFFER_SIZE	66000		// size of arrays used to capture samples
 #define IMD_TONE_1		1200		// frequency of IMD test tones
