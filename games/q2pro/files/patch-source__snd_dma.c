--- ./source/snd_dma.c.orig	Mon Dec 25 17:07:02 2006
+++ ./source/snd_dma.c	Mon Dec 25 17:07:03 2006
@@ -110,7 +110,7 @@
 #if (defined _WIN32)
 void WAVE_FillAPI( snddmaAPI_t *api );
 void DS_FillAPI( snddmaAPI_t *api );
-#elif (defined __linux__)
+#elif (defined __unix__)
 void OSS_FillAPI( snddmaAPI_t *api );
 #endif
 
@@ -129,7 +129,7 @@
 	/* fallback driver should be present on all systems */
 #if (defined _WIN32)
 	{ "wave", WAVE_FillAPI },
-#elif (defined __linux__)
+#elif (defined __unix__)
 	{ "oss", OSS_FillAPI },
 #endif
 
