--- src/gdata/tlslite/messages.py.orig	2008-12-02 03:35:34.000000000 +0100
+++ src/gdata/tlslite/messages.py	2009-11-03 21:48:12.189964805 +0100
@@ -8,8 +8,7 @@
 from X509 import X509
 from X509CertChain import X509CertChain
 
-import sha
-import md5
+import hashlib 
 
 class RecordHeader3:
     def __init__(self):
@@ -405,7 +404,8 @@
         try:
             bytes = clientRandom + serverRandom + self.write()[4:]
             s = bytesToString(bytes)
-            return stringToBytes(md5.md5(s).digest() + sha.sha(s).digest())
+            return stringToBytes(hashlib.md5(s).digest() \
+								+ hashlib.sha1(s).digest())
         finally:
             self.cipherSuite = oldCipherSuite
 
