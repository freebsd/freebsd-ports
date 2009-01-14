--- check_compilers.py.orig	2008-12-23 18:01:02.000000000 +0100
+++ check_compilers.py	2009-01-04 16:59:06.000000000 +0100
@@ -394,7 +394,7 @@
             args='-ffree-form -fdefault-integer-8', src=trivial_src['F90'])
       self.fcheck(self.is_F77_is_gfortran, 'F77 (%s) is gfortran' % self.cfg.get('F77', '?'))
       if True or not self.is_F77_is_gfortran: # on ne sait pas si les blas/lapack en ont besoin, le tester
-         self.libs.append(('math', 'g2c'))
+         self.libs.append(('math', 'f2c'))
          self.find_libs(lib=self.libs[-1])
       if self.cfg.get('F90') or self.is_F77_is_gfortran:
          self.libs.append(('math', 'gfortran'))
@@ -487,6 +487,16 @@
          else:                      # x86_64
             intel_arch   = 'intel64'
             mkl_src_name = 'mklvarsem64t.sh'
+      elif self.platform == 'FREEBSD':	# Not yet tested with icc!
+         if self.arch == 'ia64':    # ia64
+            intel_arch   = 'ia64'
+            mkl_src_name = 'mklvars64.sh'
+         elif self.arch == 'x86_64':    # x86_64
+            intel_arch   = 'ia64'
+            mkl_src_name = 'mklvars64.sh'
+         else:                      # 32 bits
+            intel_arch   = 'ia32'
+            mkl_src_name = 'mklvars32.sh'
       else:
          raise CheckCompilerError, _('Unsupported platform : %s') % self.platform
 
