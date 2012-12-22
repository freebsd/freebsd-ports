--- ./setup.py.orig	2012-11-07 00:17:06.624869638 +0100
+++ ./setup.py	2012-11-07 00:37:17.129040078 +0100
@@ -57,7 +57,7 @@
 
 pyaudio_module_sources = ['src/_portaudiomodule.c']
 
-include_dirs = []
+include_dirs = ['%%PREFIX%%/include/portaudio2']
 external_libraries = []
 extra_compile_args = ['-fno-strict-aliasing']
 extra_link_args = []
@@ -74,6 +74,9 @@
     external_libraries = ['portaudio']
     extra_link_args = []
 
+if sys.platform.startswith('freebsd'):
+    extra_link_args = ['-L%%PREFIX%%/lib/portaudio2']
+
 if sys.platform == 'darwin':
     defines += [('MACOSX', '1')]
 
@@ -83,7 +86,6 @@
 
 if STATIC_LINKING:
 
-    # platform specific configuration
     if sys.platform == 'darwin':
         extra_link_args += ['-framework', 'CoreAudio',
                             '-framework', 'AudioToolbox',
