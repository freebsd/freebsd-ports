--- Sign.py.orig	2009-05-27 14:09:55.000000000 +0200
+++ Sign.py	2009-05-27 14:13:27.000000000 +0200
@@ -11,7 +11,7 @@
 import os
 import os.path
 import string
-import md5
+import hashlib
 import time
 
 from Util import *
@@ -272,7 +272,7 @@
 
     try:
         f = open(fname, "rb")
-        m = md5.new()
+        m = hashlib.md5()
         while 1:
             # Read big blocks at a time for speed, but don't read the whole
             # file at once to reduce memory usage.
@@ -301,7 +301,7 @@
                                                              % fname) + str(e))
         return "unknown"
 
-    m = md5.new()
+    m = hashlib.md5()
 
     inquote = 0
     incomment = 0
@@ -404,7 +404,9 @@
 
 def buildcheckstr2sign(str):
     """Compute a signature from a string for the buildcheck."""
-    return hexdigest(md5.new(str))
+    m = hashlib.md5()
+    m.update(str)
+    return hexdigest(m)
 
 
 def _sign_lookup(signatures, name, key):
