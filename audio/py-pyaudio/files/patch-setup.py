--- ./setup.py.orig	2012-11-07 00:17:06.624869638 +0100
+++ ./setup.py	2012-11-07 00:37:17.129040078 +0100
@@ -74,6 +74,12 @@ else:
     external_libraries = ['portaudio']
     extra_link_args = []
 
+if sys.platform.startswith('dragonfly') or \
+   sys.platform.startswith('freebsd'):
+    include_dirs = ['%%LOCALBASE%%/include/']
+    external_libraries = []
+    extra_link_args = ['%%LOCALBASE%%/lib/libportaudio.so']
+
 if sys.platform == 'darwin':
     defines += [('MACOSX', '1')]
 
