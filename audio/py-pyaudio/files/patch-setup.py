--- setup.py.orig	2022-07-19 03:53:30 UTC
+++ setup.py
@@ -56,6 +56,12 @@ def setup_extension():
     extra_link_args = []
     defines = []
 
+    if sys.platform.startswith('dragonfly') or \
+        sys.platform.startswith('freebsd'):
+        include_dirs = ['%%LOCALBASE%%/include/']
+        external_libraries = []
+        extra_link_args = ['%%LOCALBASE%%/lib/libportaudio.so']
+
     if sys.platform == 'darwin':
         # Support only dynamic linking with portaudio, since the supported path
         # is to install portaudio using a package manager (e.g., Homebrew).
