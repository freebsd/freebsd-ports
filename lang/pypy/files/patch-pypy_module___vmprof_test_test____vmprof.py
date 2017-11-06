--- pypy/module/_vmprof/test/test__vmprof.py.orig	2017-10-30 18:35:14 UTC
+++ pypy/module/_vmprof/test/test__vmprof.py
@@ -1,3 +1,4 @@
+import py
 import sys
 from rpython.tool.udir import udir
 from pypy.tool.pytest.objspace import gettestobjspace
@@ -107,6 +108,7 @@ class AppTestVMProf(object):
         _vmprof.disable()
         assert _vmprof.is_enabled() is False
 
+    @py.test.mark.xfail(sys.platform.startswith('freebsd'), reason = "not implemented")
     def test_get_profile_path(self):
         import _vmprof
         tmpfile = open(self.tmpfilename, 'wb')
