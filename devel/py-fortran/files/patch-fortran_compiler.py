--- fortran_compiler.py.orig	Sat Jul 20 20:40:23 2002
+++ fortran_compiler.py	Thu Jul 25 11:43:52 2002
@@ -574,6 +574,7 @@
     'pgf77',
     'pgf90',
     'g77',
+    'f77',
     'g77alpha',
     'sgi',
     'vf',
@@ -654,6 +655,9 @@
 
     elif compiler_id == 'g77':
         return G77Compiler()
+
+    elif compiler_id == 'f77':
+        return F77Compiler()
 
     elif compiler_id == 'g77alpha':
         return G77Compiler(typedict = alpha_typedict)
