# HG changeset patch
# User Benjamin Peterson <benjamin@python.org>
# Date 1392869184 18000
# Node ID c9261cf05db67ec57cf66bee7b2064adef04d550
# Parent  8d1528dddc7df1002237921d3e2f22cea1cf18d5# Parent  29b1eebecb8ed946e1db8e4bb86310d681cf4a91
merge 3.2 (#20695)

--- ./Lib/test/test_urllibnet.py.orig	2014-03-04 20:56:25.532422505 +1100
+++ ./Lib/test/test_urllibnet.py	2014-03-04 20:57:48.725949896 +1100
@@ -103,7 +103,7 @@
         # Make sure fd returned by fileno is valid.
         with self.urlopen("http://www.python.org/", timeout=None) as open_url:
             fd = open_url.fileno()
-            with os.fdopen(fd, encoding='utf-8') as f:
+            with os.fdopen(fd, 'rb') as f:
                 self.assertTrue(f.read(), "reading from file created using fd "
                                           "returned by fileno failed")
 
@@ -151,7 +151,7 @@
         with self.urlretrieve("http://www.python.org/") as (file_location, info):
             self.assertTrue(os.path.exists(file_location), "file location returned by"
                             " urlretrieve is not a valid path")
-            with open(file_location, encoding='utf-8') as f:
+            with open(file_location, 'rb') as f:
                 self.assertTrue(f.read(), "reading from the file location returned"
                                 " by urlretrieve failed")
 
@@ -161,7 +161,7 @@
                               support.TESTFN) as (file_location, info):
             self.assertEqual(file_location, support.TESTFN)
             self.assertTrue(os.path.exists(file_location))
-            with open(file_location, encoding='utf-8') as f:
+            with open(file_location, 'rb') as f:
                 self.assertTrue(f.read(), "reading from temporary file failed")
 
     def test_header(self):
@@ -170,7 +170,7 @@
             self.assertIsInstance(info, email.message.Message,
                                   "info is not an instance of email.message.Message")
 
-    logo = "http://www.python.org/community/logos/python-logo-master-v3-TM.png"
+    logo = "http://www.python.org/static/community_logos/python-logo-master-v3-TM.png"
 
     def test_data_header(self):
         with self.urlretrieve(self.logo) as (file_location, fileheaders):
