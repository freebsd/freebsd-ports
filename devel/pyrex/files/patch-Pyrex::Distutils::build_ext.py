--- Pyrex/Distutils/build_ext.py.orig	Sun Dec  5 12:11:14 2004
+++ Pyrex/Distutils/build_ext.py	Sun Dec  5 12:11:41 2004
@@ -32,7 +32,7 @@
       if self.compiler == 'mingw32':
         self.swig_cpp = 1
 
-  def swig_sources (self, sources):
+  def swig_sources (self, sources, extension=None): # workaround for 2.4 compat
     if not self.extensions:
       return
 
