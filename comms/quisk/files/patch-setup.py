--- setup.py.orig	2019-04-18 17:28:40 UTC
+++ setup.py
@@ -17,23 +17,23 @@ is_64bit = sys.maxint > 2**32
 
 if sys.platform != "win32":
   missing = False
-  try:
-    import wx
-  except ImportError:
-    print ("Please install the package python-wxgtk3.0 or later")
-    missing = True
-  if not os.path.isfile("/usr/include/fftw3.h"):
-    print ("Please install the package libfftw3-dev")
-    missing = True
-  if not os.path.isdir("/usr/include/alsa"):
-    print ("Please install the package libasound2-dev")
-    missing = True
-  if not os.path.isfile("/usr/include/portaudio.h"):
-    print ("Please install the package portaudio19-dev")
-    missing = True
-  if not os.path.isdir("/usr/include/pulse"):
-    print ("please install the package libpulse-dev")
-    missing = True
+#  try:
+#    import wx
+#  except ImportError:
+#    print ("Please install the package python-wxgtk3.0 or later")
+#    missing = True
+#  if not os.path.isfile("/usr/include/fftw3.h"):
+#    print ("Please install the package libfftw3-dev")
+#    missing = True
+#  if not os.path.isdir("/usr/include/alsa"):
+#    print ("Please install the package libasound2-dev")
+#    missing = True
+#  if not os.path.isfile("/usr/include/portaudio.h"):
+#    print ("Please install the package portaudio19-dev")
+#    missing = True
+#  if not os.path.isdir("/usr/include/pulse"):
+#    print ("please install the package libpulse-dev")
+#    missing = True
   if missing:
     ans = raw_input("Do you want to continue (y, N):  ")
     ans = ans.strip()
@@ -41,6 +41,8 @@ if sys.platform != "win32":
       sys.exit(1)
 
 module1 = Extension ('quisk._quisk',
+	include_dirs = ['/usr/local/include'],
+	library_dirs = ['/usr/local/lib'],
 	libraries = ['asound', 'portaudio', 'pulse', 'fftw3', 'm'],
 	sources = ['quisk.c', 'sound.c', 'sound_alsa.c', 'sound_portaudio.c', 'sound_pulseaudio.c',
 		'is_key_down.c', 'microphone.c', 'utility.c',
@@ -94,8 +96,6 @@ modulew4 = Extension ('quisk.soapypkg.soapy',
 
 # Changes for MacOS support thanks to Mario, DL3LSM.
 modulem1 = Extension ('quisk._quisk',
-	#include_dirs = ['.'],
-	#library_dirs = ['.'],
 	libraries = ['portaudio', 'fftw3', 'm', 'pulse'],
 	sources = ['quisk.c', 'sound.c', 'sound_portaudio.c',
 		'is_key_down.c', 'microphone.c', 'utility.c',
