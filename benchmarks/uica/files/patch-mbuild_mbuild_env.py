--- mbuild/mbuild/env.py.orig	2021-04-16 20:40:24 UTC
+++ mbuild/mbuild/env.py
@@ -1237,6 +1237,12 @@ class env_t(object):
             return 'ia32'
         elif name in ['aarch64', 'arm64']:
             return 'aarch64'
+        elif name[0:3] == 'arm':
+            return 'arm'
+        elif name[0:5] == 'riscv':
+            return 'riscv'
+        elif name[0:7] == 'powerpc':
+            return 'powerpc'
         else:
             die("Unknown cpu " + name)
 
