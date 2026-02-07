--- setup.py.orig	2019-11-29 03:48:07 UTC
+++ setup.py
@@ -18,6 +18,9 @@ if sys.platform == 'darwin':
 elif sys.platform.startswith("linux"):
     platform_sources = ['c_src/simpleaudio_alsa.c', 'c_src/posix_mutex.c']
     platform_libs = ['asound']
+elif sys.platform.startswith("freebsd"):
+    platform_sources = ['c_src/simpleaudio_alsa.c', 'c_src/posix_mutex.c'] # it doesn't appear to be any other choice than ALSA
+    platform_libs = ['asound']
 elif sys.platform == 'win32':
     platform_sources = ['c_src/simpleaudio_win.c', 'c_src/windows_mutex.c']
     platform_libs = ['Winmm', 'User32']
