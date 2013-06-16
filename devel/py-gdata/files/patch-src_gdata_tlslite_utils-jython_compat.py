--- src/gdata/tlslite/utils/jython_compat.py.orig	2008-12-02 03:35:28.000000000 +0100
+++ src/gdata/tlslite/utils/jython_compat.py	2009-11-03 21:55:05.916366480 +0100
@@ -1,7 +1,7 @@
 """Miscellaneous functions to mask Python/Jython differences."""
 
 import os
-import sha
+import hashlib 
 
 if os.name != "java":
     BaseException = Exception
@@ -43,7 +43,7 @@
 
     #Factory function for getting a SHA1 object
     def getSHA1(s):
-        return sha.sha(s)
+        return hashlib.sha1(s)
 
     import sys
     import traceback
@@ -175,7 +175,7 @@
     #release, and needs to be patched
     def getSHA1(s):
         #return JCE_SHA1(s)
-        return sha.sha(s)
+        return hashlib.sha1(s)
 
 
     #Adjust the string to an array of bytes
