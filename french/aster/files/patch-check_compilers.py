--- check_compilers.py.orig	2014-07-07 21:31:29.000000000 +0200
+++ check_compilers.py	2014-08-17 17:54:05.000000000 +0200
@@ -420,8 +420,7 @@
    def after_compilers(self):
       """Define libs to search."""
       # prefer always libstdc++.so to the static one
-      self.libs.extend([('math', 'lapack'), ('math', 'blas'),
-                        ('cxx', ['libstdc++' + self._ext_shared, 'libstdc++' + self._ext_static]),])
+      self.libs.extend([('math', 'lapack'), ('math', 'blas'),])
 
    def add_on(self):
       """After searching compilers, libs... search again other bin or lib."""
