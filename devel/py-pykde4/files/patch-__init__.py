--- ./__init__.py.orig	2011-05-20 22:33:41.000000000 +0200
+++ ./__init__.py	2011-09-01 16:43:57.371033306 +0200
@@ -1,4 +1,3 @@
-import sys,DLFCN
+import sys, ctypes
 # This is needed to ensure that dynamic_cast and RTTI works inside kdelibs.
-sys.setdlopenflags(DLFCN.RTLD_NOW|DLFCN.RTLD_GLOBAL)
-     
\ No newline at end of file
+sys.setdlopenflags(ctypes.RTLD_GLOBAL)
