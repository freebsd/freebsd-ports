--- test_jbig2dec.py.orig	2015-12-01 15:52:01 UTC
+++ test_jbig2dec.py
@@ -52,6 +52,7 @@ class SelfTestSuite:
 	(len(self.fails),len(self.tests)))
     else:
       self.stream.write('PASSED all %d tests\n' % len(self.tests))
+      return 1
 
 class KnownFileHash(SelfTest):
   'self test to check for correct decode of known test files'
