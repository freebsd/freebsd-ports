--- setup.py.orig	2016-04-04 21:15:34 UTC
+++ setup.py
@@ -63,6 +63,12 @@ extra_link_args = []
 scripts = []
 defines = []
 
+if sys.platform.startswith('dragonfly') or \
+   sys.platform.startswith('freebsd'):
+    include_dirs = ['%%LOCALBASE%%/include/']
+    external_libraries = []
+    extra_link_args = ['%%LOCALBASE%%/lib/libportaudio.so']
+
 if sys.platform == 'darwin':
     defines += [('MACOSX', '1')]
     if mac_sysroot_path:
