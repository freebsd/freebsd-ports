--- setup.py.orig	2022-11-19 21:34:46 UTC
+++ setup.py
@@ -48,6 +48,15 @@ if sys.platform == "darwin":	# Build for Macintosh
     define_macros.append(("QUISK_HAVE_PULSEAUDIO", None))
   Modules = [Extension ('quisk._quisk', include_dirs=['.', base_dir + '/include'], library_dirs=['.', base_dir + '/lib'],
              libraries=libraries, sources=sources, define_macros=define_macros)]
+if "freebsd" in sys.platform:	#Build for FreeBSD
+  define_macros = [("QUISK_HAVE_PORTAUDIO", None)]	# PortAudio is always available
+  libraries = ['portaudio', 'fftw3', 'm']
+  base_dir = '%%LOCALBASE%%'
+  if os.path.isfile(base_dir + "/include/pulse/pulseaudio.h"):
+    libraries.append('pulse')
+    define_macros.append(("QUISK_HAVE_PULSEAUDIO", None))
+  Modules = [Extension ('quisk._quisk', include_dirs=['.', base_dir + '/include'], library_dirs=['.', base_dir + '/lib'],
+             libraries=libraries, sources=sources, define_macros=define_macros)]
 else:		# Linux
   define_macros = [("QUISK_HAVE_ALSA", None), ("QUISK_HAVE_PULSEAUDIO", None)]
   libraries = ['asound', 'pulse', 'fftw3', 'm']
