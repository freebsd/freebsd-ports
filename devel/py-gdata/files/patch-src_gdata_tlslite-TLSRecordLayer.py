--- src/gdata/tlslite/TLSRecordLayer.py.orig	2008-12-02 03:35:33.000000000 +0100
+++ src/gdata/tlslite/TLSRecordLayer.py	2009-11-03 21:51:47.220882123 +0100
@@ -12,8 +12,7 @@
 from utils.cryptomath import getRandomBytes
 from utils import hmac
 from FileObject import FileObject
-import sha
-import md5
+import hashlib 
 import socket
 import errno
 import traceback
@@ -116,8 +115,8 @@
         self._readBuffer = ""
 
         #Handshake digests
-        self._handshake_md5 = md5.md5()
-        self._handshake_sha = sha.sha()
+        self._handshake_md5 = hashlib.md5()
+        self._handshake_sha = hashlib.sha1()
 
         #TLS Protocol Version
         self.version = (0,0) #read-only
@@ -935,8 +934,8 @@
 
     def _handshakeStart(self, client):
         self._client = client
-        self._handshake_md5 = md5.md5()
-        self._handshake_sha = sha.sha()
+        self._handshake_md5 = hashlib.md5()
+        self._handshake_sha = hashlib.sha1()
         self._handshakeBuffer = []
         self.allegedSharedKeyUsername = None
         self.allegedSrpUsername = None
@@ -1114,9 +1113,9 @@
         imac_md5.update(label + masterSecretStr + '\x36'*48)
         imac_sha.update(label + masterSecretStr + '\x36'*40)
 
-        md5Str = md5.md5(masterSecretStr + ('\x5c'*48) + \
+        md5Str = hashlib.md5(masterSecretStr + ('\x5c'*48) + \
                          imac_md5.digest()).digest()
-        shaStr = sha.sha(masterSecretStr + ('\x5c'*40) + \
+        shaStr = hashlib.sha1(masterSecretStr + ('\x5c'*40) + \
                          imac_sha.digest()).digest()
 
         return stringToBytes(md5Str + shaStr)
