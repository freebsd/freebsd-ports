--- src/gdata/tlslite/mathtls.py.orig	2008-12-02 03:35:35.000000000 +0100
+++ src/gdata/tlslite/mathtls.py	2009-11-03 21:45:19.140316480 +0100
@@ -4,8 +4,7 @@
 from utils.cryptomath import *
 
 import hmac
-import md5
-import sha
+import hashlib
 
 #1024, 1536, 2048, 3072, 4096, 6144, and 8192 bit groups]
 goodGroupParameters = [(2,0xEEAF0AB9ADB38DD69C33F80AFA8FC5E86072618775FF3C0B9EA2314C9C256576D674DF7496EA81D3383B4813D692C6E0E0D5D8E250B98BE48E495C1D6089DAD15DC7D7B46154D6B6CE8EF4AD69B15D4982559B297BCF1885C529F566660E57EC68EDBC3C05726CC02FD4CBF4976EAA9AFD5138FE8376435B9FC61D2FC0EB06E3),\
@@ -38,8 +37,10 @@
     S2 = secret[ int(math.floor(len(secret)/2.0)) : ]
 
     #Run the left half through P_MD5 and the right half through P_SHA1
-    p_md5 = P_hash(md5, S1, concatArrays(stringToBytes(label), seed), length)
-    p_sha1 = P_hash(sha, S2, concatArrays(stringToBytes(label), seed), length)
+    p_md5 = P_hash(hashlib.md5, S1, concatArrays(stringToBytes(label), \
+					seed), length)
+    p_sha1 = P_hash(hashlib.sha1, S2, concatArrays(stringToBytes(label), \
+					seed), length)
 
     #XOR the output values and return the result
     for x in range(length):
@@ -54,8 +55,8 @@
     index = 0
     for x in range(26):
         A = chr(ord('A')+x) * (x+1) # 'A', 'BB', 'CCC', etc..
-        input = secretStr + sha.sha(A + secretStr + seedStr).digest()
-        output = md5.md5(input).digest()
+        input = secretStr + hashlib.sha1(A + secretStr + seedStr).digest()
+        output = hashlib.md5(input).digest()
         for c in output:
             if index >= length:
                 return bytes
@@ -68,7 +69,8 @@
         raise ValueError("username too long")
     if len(salt)>=256:
         raise ValueError("salt too long")
-    return stringToNumber(sha.sha(salt + sha.sha(username + ":" + password)\
+    return stringToNumber(hashlib.sha1(salt + \
+					hashlib.sha1(username + ":" + password)\
            .digest()).digest())
 
 #This function is used by VerifierDB.makeVerifier
@@ -88,10 +90,10 @@
     return s
 
 def makeU(N, A, B):
-  return stringToNumber(sha.sha(PAD(N, A) + PAD(N, B)).digest())
+  return stringToNumber(hashlib.sha1(PAD(N, A) + PAD(N, B)).digest())
 
 def makeK(N, g):
-  return stringToNumber(sha.sha(numberToString(N) + PAD(N, g)).digest())
+  return stringToNumber(hashlib.sha1(numberToString(N) + PAD(N, g)).digest())
 
 
 """
@@ -113,8 +115,7 @@
         digestmod: A module supporting PEP 247. Defaults to the md5 module.
         """
         if digestmod is None:
-            import md5
-            digestmod = md5
+            digestmod = hashlib.md5
 
         if key == None: #TREVNEW - for faster copying
             return      #TREVNEW
