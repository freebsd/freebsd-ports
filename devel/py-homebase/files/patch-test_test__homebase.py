--- test/test_homebase.py.orig	2022-08-14 16:40:47 UTC
+++ test/test_homebase.py
@@ -667,7 +667,7 @@ class TestHomebaseVirtualEnv(TestHomebase):
             sys.prefix = sys.base_prefix
 
 
-@unittest.skipUnless(sys.platform.startswith('linux'), 'TestHomebaseLinuxXDG: Not Linux')
+@unittest.skipUnless(sys.platform.startswith('linux') or sys.platform.startswith('freebsd'), 'TestHomebaseLinuxXDG: Not Linux')
 @unittest.skipIf('travis' in os.path.expanduser('~'), 'Skipping travis virtualenv tests for now.')
 class TestHomebaseLinuxXDG(TestHomebase):
 
