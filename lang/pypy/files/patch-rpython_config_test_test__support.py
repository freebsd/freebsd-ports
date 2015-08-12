--- rpython/config/test/test_support.py.orig	2015-05-31 07:19:51 UTC
+++ rpython/config/test/test_support.py
@@ -52,25 +52,30 @@ def test_cpuinfo_linux():
     finally:
         os.environ = saved
 
-def test_cpuinfo_darwin():
-    if sys.platform != 'darwin':
-        py.test.skip('mac only')
-    saved_func = support.darwin_get_cpu_count
+def test_cpuinfo_sysctl():
+    if sys.platform != 'darwin' and not sys.platform.startswith('freebsd'):
+        py.test.skip('mac and bsd only')
+    saved_func = support.sysctl_get_cpu_count
     saved = os.environ
-    def count():
+    def count(cmd):
+        if sys.platform == 'darwin':
+            assert cmd == '/usr/sbin/sysctl'
+        else:
+            assert cmd == '/sbin/sysctl'
         return 42
     try:
-        support.darwin_get_cpu_count = count
+        support.sysctl_get_cpu_count = count
         os.environ = FakeEnviron(None)
         assert support.detect_number_of_processors() == 42
         os.environ = FakeEnviron('-j2')
         assert support.detect_number_of_processors() == 1
     finally:
         os.environ = saved
-        support.darwin_get_cpu_count = saved_func
+        support.sysctl_get_cpu_count = saved_func
 
-def test_darwin_get_cpu_count():
-    if sys.platform != 'darwin':
+def test_sysctl_get_cpu_count():
+    if sys.platform != 'darwin' and not sys.platform.startswith('freebsd'):
         py.test.skip('mac only')
-    assert support.darwin_get_cpu_count() > 0 # hopefully
-    assert support.darwin_get_cpu_count("false") == 1
+    cmd = '/usr/sbin/sysctl' if sys.platform != 'darwin' else '/sbin/sysctl'
+    assert support.sysctl_get_cpu_count(cmd) > 0 # hopefully
+    assert support.sysctl_get_cpu_count(cmd, "false") == 1
