--- tests/functional/qemu_test/decorators.py.orig	2025-11-25 22:22:39 UTC
+++ tests/functional/qemu_test/decorators.py
@@ -6,6 +6,7 @@ import resource
 import os
 import platform
 import resource
+import subprocess
 from unittest import skipIf, skipUnless
 
 from .cmd import which
@@ -165,3 +166,24 @@ def skipLockedMemoryTest(locked_memory):
         ulimit_memory == resource.RLIM_INFINITY or ulimit_memory >= locked_memory * 1024,
         f'Test required {locked_memory} kB of available locked memory',
     )
+
+def skipIfInsideFreeBSDJail():
+    '''
+    Decorator to skip execution in a FreeBSD jail
+
+      @skipIfInsideFreeBSDJail()
+    '''
+    jailed = False
+    try:
+        result = subprocess.run(
+            ['sysctl', '-n', 'security.jail.jailed'],
+            capture_output=True,
+            text=True,
+            check=True
+          )
+        jailed = result.stdout.strip() == '1'
+    except Exception:
+        pass
+
+    return skipIf(platform.system() == 'FreeBSD' and jailed,
+                  'running inside the FreeBSD jail')
