--- sound/sdlsound.c.orig	2007-04-27 23:18:27.000000000 +0200
+++ sound/sdlsound.c	2007-07-29 14:54:59.000000000 +0200
@@ -52,6 +52,15 @@
 /* Records sound writer status information */
 static int audio_output_started;
 
+/*
+ * log2() seems to be a Linuxism, define it here as it is absent in libm
+ */
+double
+log2(double x)
+{
+	return log(x)/log(2);
+}
+
 int
 sound_lowlevel_init( const char *device, int *freqptr, int *stereoptr )
 {
