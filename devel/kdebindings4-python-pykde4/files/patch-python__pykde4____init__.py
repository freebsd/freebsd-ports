--- ./python/pykde4/__init__.py.orig	2008-07-22 04:00:52.000000000 +0400
+++ ./python/pykde4/__init__.py	2009-05-03 23:18:43.000000000 +0400
@@ -1,4 +1,3 @@
-import sys,DLFCN
+import sys, ctypes
 # This is needed to ensure that dynamic_cast and RTTI works inside kdelibs.
-sys.setdlopenflags(DLFCN.RTLD_NOW|DLFCN.RTLD_GLOBAL)
-     
\ No newline at end of file
+sys.setdlopenflags(ctypes.RTLD_GLOBAL)
