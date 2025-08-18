--- setup.py.orig	2025-01-25 08:39:20 UTC
+++ setup.py
@@ -45,10 +45,10 @@ if platformname == 'darwin':
         '-Werror-implicit-function-declaration',
         '-Wfatal-errors'
     ]
-elif platformname == 'linux':
+elif platformname == 'linux' or platformname == 'freebsd':
     libraries.append('lo')
-    include_dirs.extend(['/usr/include', '/usr/local/include'])
-    library_dirs.append("/usr/local/lib")
+    include_dirs.extend(['/usr/include', '%%PREFIX%%/include'])
+    library_dirs.append("%%PREFIX%%/lib")
     compile_args += [
         '-fno-strict-aliasing',
         '-Werror-implicit-function-declaration',
