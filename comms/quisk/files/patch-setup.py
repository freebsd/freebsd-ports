--- setup.py.orig	2015-11-27 20:41:34 UTC
+++ setup.py
@@ -12,8 +12,8 @@ fp.write("#QUISK version %s\n" % Version
 fp.close()
 
 module1 = Extension ('quisk._quisk',
-	#include_dirs = ['.'],
-	#library_dirs = ['.'],
+	include_dirs = ['%%LOCALBASE%%/include/portaudio2', '%%LOCALBASE%%/include'],
+	library_dirs = ['%%LOCALBASE%%/lib/portaudio2', '%%LOCALBASE%%/lib'],
 	libraries = ['asound', 'portaudio', 'pulse', 'fftw3', 'm'],
 	sources = ['quisk.c', 'sound.c', 'sound_alsa.c', 'sound_portaudio.c', 'sound_pulseaudio.c',
 		'is_key_down.c', 'microphone.c', 'utility.c',
