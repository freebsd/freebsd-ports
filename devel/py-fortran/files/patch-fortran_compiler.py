--- fortran_compiler.py.orig	2005-09-20 18:08:08 UTC
+++ fortran_compiler.py
@@ -703,6 +703,7 @@ compiler_ids = [
     'pgf77',
     'pgf90',
     'g77',
+    'f77',
     'g77alpha',
     'sgi',
     'vf',
@@ -801,6 +802,9 @@ def get_compiler (compiler_id):
     elif compiler_id == 'g77':
         return G77Compiler()
 
+    elif compiler_id == 'f77':
+        return F77Compiler()
+
     elif compiler_id == 'g77alpha':
         return G77Compiler(typedict = alpha_typedict)
 
