--- check_compilers.py.orig	2010-12-22 17:42:47.000000000 +0100
+++ check_compilers.py	2010-12-27 23:35:57.000000000 +0100
@@ -602,6 +602,16 @@
             else:                      # x86_64
                intel_arch   = 'intel64'
                mkl_src_name = 'mklvarsem64t.sh'
+         elif self.platform == 'FREEBSD':	# Not yet tested with icc!
+            if self.arch == 'ia64':    # ia64
+               intel_arch   = 'ia64'
+               mkl_src_name = 'mklvars64.sh'
+            elif self.arch == 'x86_64':    # x86_64
+               intel_arch   = 'ia64'
+               mkl_src_name = 'mklvars64.sh'
+            else:                      # 32 bits
+               intel_arch   = 'ia32'
+               mkl_src_name = 'mklvars32.sh'
          else:
             raise CheckCompilerError(_('Unsupported platform : %s') % self.platform)
 
