--- tests/test.py.orig	2018-01-08 10:57:15 UTC
+++ tests/test.py
@@ -134,7 +134,7 @@ class TestUploader(unittest.TestCase):
                 self.assertEqual(codecov.main(), None)
                 assert post.called and put.called
 
-    @unittest.skipIf(os.getenv('CI') == "True" and os.getenv('APPVEYOR') == 'True', 'Skip AppVeyor CI test')
+    @unittest.skipIf(sys.platform.startswith('freebsd'),'Skip test')
     def test_send(self):
         with patch('requests.post') as post:
             with patch('requests.put') as put:
@@ -249,7 +249,7 @@ class TestUploader(unittest.TestCase):
         else:
             raise Exception("Did not raise AssertionError")
 
-    @unittest.skipIf(os.getenv('CI') == "True" and os.getenv('APPVEYOR') == 'True', 'Skip AppVeyor CI test')
+    @unittest.skipIf(sys.platform.startswith('freebsd'),'Skip test')
     def test_bowerrc_none(self):
         with open(self.bowerrc, 'w+') as f:
             f.write('{"other_key": "tests"}')
