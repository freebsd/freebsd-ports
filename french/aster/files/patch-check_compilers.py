--- check_compilers.py.orig	2014-03-05 09:41:19.000000000 +0100
+++ check_compilers.py	2014-03-17 18:52:14.000000000 +0100
@@ -413,8 +413,7 @@
    def after_compilers(self):
       """Define libs to search."""
       # prefer always libstdc++.so to the static one
-      self.libs.extend([('math', 'lapack'), ('math', 'blas'),
-                        ('cxx', ['libstdc++.so', 'libstdc++.a']),])
+      self.libs.extend([('math', 'lapack'), ('math', 'blas'),])
 
    def add_on(self):
       """After searching compilers, libs... search again other bin or lib."""
