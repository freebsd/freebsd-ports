--- breezy/tests/test_setup.py.orig	2022-03-20 00:01:04 UTC
+++ breezy/tests/test_setup.py
@@ -16,11 +16,12 @@
 
 """Test for setup.py build process"""
 
-from distutils import version
 import os
 import sys
 import subprocess
 
+from packaging.version import Version
+
 import breezy
 from .. import tests
 
@@ -90,6 +91,6 @@ class TestDistutilsVersion(tests.TestCase):
     def test_version_with_string(self):
         # We really care about two pyrex specific versions and our ability to
         # detect them
-        lv = version.LooseVersion
+        lv = Version
         self.assertTrue(lv("0.9.4.1") < lv('0.17.beta1'))
         self.assertTrue(lv("0.9.6.3") < lv('0.10'))
