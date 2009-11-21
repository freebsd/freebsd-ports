--- src/gdata/tlslite/utils/cryptomath.py.orig	2008-12-02 03:35:26.000000000 +0100
+++ src/gdata/tlslite/utils/cryptomath.py	2009-11-03 21:06:12.475992458 +0100
@@ -6,7 +6,7 @@
 import math
 import base64
 import binascii
-import sha
+import hashlib
 
 from compat import *
 
@@ -195,7 +195,7 @@
     return int(math.ceil(bits / 8.0))
 
 def hashAndBase64(s):
-    return stringToBase64(sha.sha(s).digest())
+    return stringToBase64(hashlib.sha1(s).digest())
 
 def getBase64Nonce(numChars=22): #defaults to an 132 bit nonce
     bytes = getRandomBytes(numChars)
