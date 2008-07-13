--- check_compilers.py.orig	2008-07-03 18:50:57.000000000 +0200
+++ check_compilers.py	2008-07-08 00:01:13.000000000 +0200
@@ -290,7 +290,7 @@
       if self.platform == 'LINUX64':
          self.F77 = 'gfortran'
 
-      self.libs.extend([('math', 'lapack'), ('math', 'blas'), ('math', 'g2c'),
+      self.libs.extend([('math', 'lapack'), ('math', 'blas'), ('math', 'f2c'),
                         ('cxx', ['libstdc++.so', 'libstdc++.a']),])
 
 #-------------------------------------------------------------------------------
@@ -332,7 +332,7 @@
       if self.platform == 'LINUX64':
          self.F77 = 'gfortran'
 
-      self.libs.extend([('math', 'g2c'),
+      self.libs.extend([('math', 'f2c'),
                         ('cxx', ['libstdc++.so', 'libstdc++.a']),])
 
 #-------------------------------------------------------------------------------
@@ -356,6 +356,13 @@
             self.profiles.append('mklvars64.sh')
          else:                      # x86_64
             self.profiles.append('mklvarsem64t.sh')
+      elif self.platform == 'FREEBSD':	# Not yet tested with icc!
+         if self.arch == 'ia64':    # ia64
+            self.profiles.append('mklvars64.sh')
+         elif self.arch == 'x86_64':    # x86_64
+            self.profiles.append('mklvarsem64t.sh')
+         else:                      # 32 bits
+            self.profiles.append('mklvars32.sh')
       else:
          raise CheckCompilerError, _('Unsupported platform : %s') % self.platform
       
