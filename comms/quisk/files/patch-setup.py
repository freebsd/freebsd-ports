--- setup.py.orig	2016-12-08 22:14:02 UTC
+++ setup.py
@@ -12,8 +12,8 @@ fp.write("#Quisk version %s\n" % Version
 fp.close()
 
 module1 = Extension ('quisk._quisk',
-	#include_dirs = ['.'],
-	#library_dirs = ['.'],
+	include_dirs = ['%%LOCALBASE%%/include'],
+	library_dirs = ['%%LOCALBASE%%/lib'],
 	libraries = ['asound', 'portaudio', 'pulse', 'fftw3', 'm'],
 	sources = ['quisk.c', 'sound.c', 'sound_alsa.c', 'sound_portaudio.c', 'sound_pulseaudio.c',
 		'is_key_down.c', 'microphone.c', 'utility.c',
@@ -116,7 +116,7 @@ control the N8LP LP-PAN panadapter and t
 	author_email = 'jahlstr@gmail.com',
 	url = 'http://james.ahlstrom.name/quisk/',
 	download_url = 'http://james.ahlstrom.name/quisk/',
-	packages = ['quisk', 'quisk.sdriqpkg', 'quisk.n2adr', 'quisk.softrock', 'quisk.usb'],
+	packages = ['quisk', 'quisk.sdriqpkg', 'quisk.n2adr', 'quisk.softrock', 'quisk.usb', 'quisk.hermes'],
 	package_dir =  {'quisk' : '.'},
 	package_data = {'quisk' : ['*.txt', '*.html']},
 	ext_modules = Modules,
