Obtained from:	https://github.com/tahoe-lafs/zfec/commit/0441f248ffec150c9c27191b0b7a69a7364a5e7c

--- zfec/filefec.py.orig	2018-02-06 21:53:51 UTC
+++ zfec/filefec.py
@@ -1,14 +1,35 @@
 from __future__ import print_function
 import array, os, struct
 from base64 import b32encode
-from pyutil import fileutil
-from pyutil.mathutil import pad_size, log_ceil
 
 import zfec
 from zfec import easyfec
 
 CHUNKSIZE = 4096
 
+def pad_size(n, k):
+    """
+    The smallest number that has to be added to n to equal a multiple of k.
+    """
+    if n%k:
+        return k - n%k
+    else:
+        return 0
+
+def log_ceil(n, b):
+    """
+    The smallest integer k such that b^k >= n.
+
+    log_ceil(n, 2) is the number of bits needed to store any of n values, e.g.
+    the number of bits needed to store any of 128 possible values is 7.
+    """
+    p = 1
+    k = 0
+    while p < n:
+        p *= b
+        k += 1
+    return k
+
 def ab(x): # debuggery
     if len(x) >= 3:
         return "%s:%s" % (len(x), b32encode(x[-3:]),)
@@ -224,7 +245,10 @@ def encode_to_files(inf, fsize, dirname, prefix, k, m,
             for fn in fns:
                 if verbose:
                     print("Cleaning up: trying to remove %r..." % (fn,))
-                fileutil.remove_if_possible(fn)
+                try:
+                    os.remove(fn)
+                except EnvironmentError:
+                    pass
             return 1
     if verbose:
         print()
