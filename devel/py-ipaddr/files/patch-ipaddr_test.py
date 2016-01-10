--- ipaddr_test.py.orig	2016-01-05 00:38:35 UTC
+++ ipaddr_test.py
@@ -21,6 +21,10 @@
 import unittest
 import time
 import ipaddr
+import sys
+
+if sys.version_info > (3,):
+    long = int
 
 # Compatibility function to cast str to bytes objects
 if issubclass(ipaddr.Bytes, str):
@@ -266,7 +270,7 @@ class IpaddrUnitTest(unittest.TestCase):
                          '2001:658:22a:cafe:200::1')
 
     def testGetNetmask(self):
-        self.assertEqual(int(self.ipv4.netmask), 4294967040L)
+        self.assertEqual(int(self.ipv4.netmask), 4294967040)
         self.assertEqual(str(self.ipv4.netmask), '255.255.255.0')
         self.assertEqual(str(self.ipv4_hostmask.netmask), '255.0.0.0')
         self.assertEqual(int(self.ipv6.netmask),
@@ -283,7 +287,7 @@ class IpaddrUnitTest(unittest.TestCase):
         self.assertEqual(ipv6_zero_netmask._prefix_from_prefix_string('0'), 0)
 
     def testGetBroadcast(self):
-        self.assertEqual(int(self.ipv4.broadcast), 16909311L)
+        self.assertEqual(int(self.ipv4.broadcast), 16909311)
         self.assertEqual(str(self.ipv4.broadcast), '1.2.3.255')
 
         self.assertEqual(int(self.ipv6.broadcast),
@@ -1100,9 +1104,9 @@ class IpaddrUnitTest(unittest.TestCase):
 
     def testNetworkElementCaching(self):
         # V4 - make sure we're empty
-        self.assertFalse(self.ipv4._cache.has_key('network'))
-        self.assertFalse(self.ipv4._cache.has_key('broadcast'))
-        self.assertFalse(self.ipv4._cache.has_key('hostmask'))
+        self.assertFalse('network' in self.ipv4._cache)
+        self.assertFalse('broadcast' in self.ipv4._cache)
+        self.assertFalse('hostmask' in self.ipv4._cache)
 
         # V4 - populate and test
         self.assertEqual(self.ipv4.network, ipaddr.IPv4Address('1.2.3.0'))
@@ -1110,14 +1114,14 @@ class IpaddrUnitTest(unittest.TestCase):
         self.assertEqual(self.ipv4.hostmask, ipaddr.IPv4Address('0.0.0.255'))
 
         # V4 - check we're cached
-        self.assertTrue(self.ipv4._cache.has_key('network'))
-        self.assertTrue(self.ipv4._cache.has_key('broadcast'))
-        self.assertTrue(self.ipv4._cache.has_key('hostmask'))
+        self.assertTrue('network' in self.ipv4._cache)
+        self.assertTrue('broadcast' in self.ipv4._cache)
+        self.assertTrue('hostmask' in self.ipv4._cache)
 
         # V6 - make sure we're empty
-        self.assertFalse(self.ipv6._cache.has_key('network'))
-        self.assertFalse(self.ipv6._cache.has_key('broadcast'))
-        self.assertFalse(self.ipv6._cache.has_key('hostmask'))
+        self.assertFalse('network' in self.ipv6._cache)
+        self.assertFalse('broadcast' in self.ipv6._cache)
+        self.assertFalse('hostmask' in self.ipv6._cache)
 
         # V6 - populate and test
         self.assertEqual(self.ipv6.network,
@@ -1128,9 +1132,9 @@ class IpaddrUnitTest(unittest.TestCase):
                          ipaddr.IPv6Address('::ffff:ffff:ffff:ffff'))
 
         # V6 - check we're cached
-        self.assertTrue(self.ipv6._cache.has_key('network'))
-        self.assertTrue(self.ipv6._cache.has_key('broadcast'))
-        self.assertTrue(self.ipv6._cache.has_key('hostmask'))
+        self.assertTrue('network' in self.ipv6._cache)
+        self.assertTrue('broadcast' in self.ipv6._cache)
+        self.assertTrue('hostmask' in self.ipv6._cache)
 
     def testTeredo(self):
         # stolen from wikipedia
