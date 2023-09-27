--- setup.py.orig	2023-08-22 09:51:12 UTC
+++ setup.py
@@ -25,7 +25,9 @@ import os
 import subprocess
 import sys
 
-packages = ['gphoto2', 'gphoto2.examples']
+packages = ['gphoto2']
+if 'WITH_EXAMPLES' in os.environ:
+    packages.append('gphoto2.examples')
 package_dir = {'gphoto2.examples': 'examples'}
 package_data = {'gphoto2.examples': ['*']}
 exclude_package_data = {'': ['*.c']}
@@ -141,7 +143,7 @@ mod_src_dir = os.path.join('src', mod_src_dir)
 package_dir['gphoto2'] = mod_src_dir
 
 extra_compile_args = [
-    '-O3', '-Wno-unused-variable', '-Wno-unused-but-set-variable',
+    '-Wno-unused-variable', '-Wno-unused-but-set-variable',
     '-Wno-unused-label', '-Wno-strict-prototypes']
 if 'PYTHON_GPHOTO2_STRICT' in os.environ:
     extra_compile_args.append('-Werror')
