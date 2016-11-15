--- check_compilers.py.orig	2016-09-07 08:44:22 UTC
+++ check_compilers.py
@@ -420,8 +420,7 @@ class GNU_COMPILER(CONFIGURE_COMPILER):
    def after_compilers(self):
       """Define libs to search."""
       # prefer always libstdc++.so to the static one
-      self.libs.extend([('math', 'lapack'), ('math', 'blas'),
-                        ('cxx', ['libstdc++' + self._ext_shared, 'libstdc++' + self._ext_static]),])
+      self.libs.extend([('math', 'lapack'), ('math', 'blas'),])
 
    def add_on(self):
       """After searching compilers, libs... search again other bin or lib."""
