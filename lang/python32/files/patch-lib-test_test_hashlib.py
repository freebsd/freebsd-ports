--- Lib/test/test_hashlib.py.orig	2005-08-21 19:45:59.000000000 +0100
+++ Lib/test/test_hashlib.py	2008-08-30 10:43:27.000000000 +0100
@@ -9,7 +9,7 @@
 import hashlib
 import unittest
 from test import test_support
-
+from test.test_support import _4G, precisionbigmemtest
 
 def hexstr(s):
     import string
@@ -55,7 +55,6 @@
             m2.update(aas + bees + cees)
             self.assertEqual(m1.digest(), m2.digest())
 
-
     def check(self, name, data, digest):
         # test the direct constructors
         computed = getattr(hashlib, name)(data).hexdigest()
@@ -75,6 +74,21 @@
         self.check('md5', 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789',
                    'd174ab98d277d9f5a5611c2c9f419d9f')
 
+    @precisionbigmemtest(size=_4G + 5, memuse=1)
+    def test_case_md5_huge(self, size):
+        if size == _4G + 5:
+            try:
+                self.check('md5', 'A'*size, 'c9af2dff37468ce5dfee8f2cfc0a9c6d')
+            except OverflowError:
+                pass # 32-bit arch
+
+    @precisionbigmemtest(size=_4G - 1, memuse=1)
+    def test_case_md5_uintmax(self, size):
+        if size == _4G - 1:
+            try:
+                self.check('md5', 'A'*size, '28138d306ff1b8281f1a9067e1a1a2b3')
+            except OverflowError:
+                pass # 32-bit arch
 
     # use the three examples from Federal Information Processing Standards
     # Publication 180-1, Secure Hash Standard,  1995 April 17
