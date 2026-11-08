--- test/hooks.on-modify.test.py.orig	2025-08-16 19:02:31 UTC
+++ test/hooks.on-modify.test.py
@@ -158,6 +158,10 @@ class TestHooksOnModify(TestCase):
         logs = hook.get_logs()
         self.assertEqual(logs["output"]["msgs"][0], "FEEDBACK")
 
+    # On FreeBSD libfaketime's LD_PRELOAD, which is inherited by the bash
+    # hook wrapper, deadlocks the wrapper's process substitution.
+    @unittest.skipIf(sys.platform.startswith("freebsd"),
+                     "libfaketime hangs the logged hook wrapper on FreeBSD")
     def test_onmodify_revert_changes(self):
         """on-modify-revert - revert all user modifications."""
         hookname = "on-modify-revert"
