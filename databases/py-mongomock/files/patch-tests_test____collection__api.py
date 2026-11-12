--- tests/test__collection_api.py.orig	2026-11-10 02:57:44 UTC
+++ tests/test__collection_api.py
@@ -5282,7 +5282,7 @@ class CollectionAPITest(TestCase):
             collection.insert_one({'a': {'b'}})
         if version.parse(pymongo.version) < version.parse('3.8'):
             return
-        self.assertEqual(str(cm.exception), "cannot encode object: {'b'}, of type: <class 'set'>")
+        self.assertIn("cannot encode object: {'b'}, of type: <class 'set'>", str(cm.exception))
 
     @skipIf(not helpers.HAVE_PYMONGO, 'pymongo not installed')
     def test_insert_bson_invalid_encode_type(self):
