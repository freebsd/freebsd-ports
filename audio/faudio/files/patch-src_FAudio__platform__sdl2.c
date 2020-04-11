https://github.com/FNA-XNA/FAudio/issues/183

--- src/FAudio_platform_sdl2.c.orig	2020-04-01 14:55:30 UTC
+++ src/FAudio_platform_sdl2.c
@@ -100,6 +100,18 @@ void FAudio_PlatformInit(
 		want.samples = want.freq / 100;
 	}
 
+	/* SDL audio with arts/dsp backends expect ^2, so round up.
+	 * For 48KHz this should be 512.
+	 * https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
+        */
+	want.samples--;
+	want.samples |= want.samples >> 1;
+	want.samples |= want.samples >> 2;
+	want.samples |= want.samples >> 4;
+	want.samples |= want.samples >> 8;
+	want.samples |= want.samples >> 16;
+	want.samples++;
+
 	/* Open the device (or at least try to) */
 iosretry:
 	device = SDL_OpenAudioDevice(
