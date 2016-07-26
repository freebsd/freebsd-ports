--- setup.py.orig	2015-10-19 05:48:12 UTC
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
