--- tests/functional/qemu_test/decorators.py.orig	2026-10-09 00:25:04 UTC
+++ tests/functional/qemu_test/decorators.py
@@ -180,6 +180,27 @@ def skipLockedMemoryTest(locked_memory):
     )
 
 '''
+Decorator to skip execution in a FreeBSD jail
+
+@skipIfInsideFreeBSDJail()
+'''
+def skipIfInsideFreeBSDJail():
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
+
+'''
 Decorator to skip execution of a test if passwordless
 sudo command is not available.
 '''
