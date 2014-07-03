--- setup.py.orig	2014-06-01 15:30:01.000000000 -0700
+++ setup.py	2014-06-01 15:31:15.000000000 -0700
@@ -11,8 +11,8 @@
 fp.close()
 
 module1 = Extension ('quisk._quisk',
-	#include_dirs = ['.'],
-	#library_dirs = ['.'],
+	include_dirs = ['%%LOCALBASE%%/include/portaudio2', '%%LOCALBASE%%/include'],
+	library_dirs = ['%%LOCALBASE%%/lib/portaudio2', '%%LOCALBASE%%/lib'],
 	libraries = ['asound', 'portaudio', 'pulse-simple', 'fftw3', 'm'],
 	sources = ['quisk.c', 'sound.c', 'sound_alsa.c', 'sound_portaudio.c', 'sound_pulseaudio.c',
 		'is_key_down.c', 'microphone.c', 'utility.c',
