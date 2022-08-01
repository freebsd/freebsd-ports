--- mbuild/mbuild/env.py.orig	2021-04-16 20:40:24 UTC
+++ mbuild/mbuild/env.py
@@ -1237,6 +1237,8 @@ class env_t(object):
             return 'ia32'
         elif name in ['aarch64', 'arm64']:
             return 'aarch64'
+        elif name[0:3] == 'arm':
+            return 'arm'
         else:
             die("Unknown cpu " + name)
 
