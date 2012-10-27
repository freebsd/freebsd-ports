--- qemuwrapper/qemuwrapper.py.orig	2012-10-27 00:41:23.000000000 +0200
+++ qemuwrapper/qemuwrapper.py	2012-10-27 00:43:33.000000000 +0200
@@ -83,7 +83,7 @@
 __author__ = 'Thomas Pani and Jeremy Grossmann'
 __version__ = '0.8.3.1'
 
-if platform.system() == 'Windows':
+if platform.system() == 'Windows' or platform.system().__contains__("BSD"):
     QEMU_PATH = "qemu" # we still use Qemu 0.11.0 on Windows
 else:
     QEMU_PATH = "qemu-system-i386"
