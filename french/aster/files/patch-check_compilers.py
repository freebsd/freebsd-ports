--- check_compilers.py.orig	2009-06-16 14:26:10.000000000 +0200
+++ check_compilers.py	2009-06-19 23:08:19.000000000 +0200
@@ -268,9 +268,9 @@
          self._print('---------- ERROR MESSAGE ----------', os.linesep, errmsg)
          self._print(blas_lapack['__error__'])
          rep = should_continue()
-      # add to global (g2c/gfortran must be used by aster compiled with Intel)
+      # add to global (f2c/gfortran must be used by aster compiled with Intel)
       for k, v in self.cfg.items():
-         if    re.search('__LIBS_math_[0-9]+_g2c',      k) is not None \
+         if    re.search('__LIBS_math_[0-9]+_f2c',      k) is not None \
             or re.search('__LIBS_math_[0-9]+_gfortran', k) is not None:
             self.cfg_add_global[k] = v
 
@@ -416,8 +416,8 @@
       self.fcheck(self.fortran_supports_openmp, "F77 (%s) and F90 (%s) support '-fopenmp' option" \
          % (self.cfg.get('F77', '?'), self.cfg.get('F90', '?')))
       
-      # les blas/lapack en ont peut-etre besoin, on rend libg2c facultative si F77=gfortran
-      self.libs.append(('math', 'g2c', not self.is_F77_is_gfortran))
+      # les blas/lapack en ont peut-etre besoin, on rend libf2c facultative si F77=gfortran
+      self.libs.append(('math', 'f2c', not self.is_F77_is_gfortran))
       self.find_libs(lib=self.libs[-1])
       if self.cfg.get('F90') or self.is_F77_is_gfortran:
          self.libs.append(('math', 'gfortran'))
@@ -518,6 +518,16 @@
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
 
