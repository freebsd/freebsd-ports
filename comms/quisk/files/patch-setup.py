--- setup.py.orig	2024-05-10 17:22:55 UTC
+++ setup.py
@@ -54,6 +54,15 @@ elif "freebsd" in sys.platform:	#Build for FreeBSD
   define_macros = [("QUISK_HAVE_PULSEAUDIO", None)] # Pulseaudio is in FreeBSD base
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
