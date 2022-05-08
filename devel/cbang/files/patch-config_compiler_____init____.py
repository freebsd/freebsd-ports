--- config/compiler/__init__.py.orig	2021-08-10 22:46:49 UTC
+++ config/compiler/__init__.py
@@ -308,7 +308,7 @@ def configure(conf, cstd = 'c99'):
     # Optimizations
     if optimize:
         if compiler_mode == 'gnu':
-            env.AppendUnique(CCFLAGS = ['-O3', '-funroll-loops'])
+            env.AppendUnique(CCFLAGS = ['-funroll-loops'])
 
         elif compiler_mode == 'msvc':
             env.AppendUnique(CCFLAGS = ['/O2', '/Zc:throwingNew'])
