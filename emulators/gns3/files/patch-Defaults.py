--- src/GNS3/Config/Defaults.py.orig	2012-10-22 19:17:09.000000000 +0200
+++ src/GNS3/Config/Defaults.py	2012-10-27 00:55:58.000000000 +0200
@@ -65,7 +65,7 @@
     QEMUWRAPPER_DEFAULT_WORKDIR = unicode('/tmp')
 
 # Default paths to Qemu and qemu-img
-if sys.platform.startswith('win'):
+if sys.platform.startswith('win') or sys.platform.startswith('freebsd'):
     QEMU_DEFAULT_PATH = unicode('qemu')
     QEMU_IMG_DEFAULT_PATH = unicode('qemu-img')
 else:
