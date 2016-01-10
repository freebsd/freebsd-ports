--- ipaddr.py.orig	2014-01-31 21:22:32 UTC
+++ ipaddr.py
@@ -25,6 +25,11 @@ and networks.
 __version__ = '2.1.11'
 
 import struct
+import sys
+
+if sys.version_info > (3,):
+    long = int
+    xrange = range
 
 IPV4LENGTH = 32
 IPV6LENGTH = 128
@@ -1447,7 +1452,7 @@ class _BaseV6(object):
 
         try:
             # Now, parse the hextets into a 128-bit integer.
-            ip_int = 0L
+            ip_int = long(0)
             for i in xrange(parts_hi):
                 ip_int <<= 16
                 ip_int |= self._parse_hextet(parts[i])
