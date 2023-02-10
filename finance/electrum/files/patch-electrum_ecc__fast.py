--- electrum/ecc_fast.py.orig	2023-01-14 09:57:57 UTC
+++ electrum/ecc_fast.py
@@ -46,8 +46,8 @@ def load_library():
     elif 'ANDROID_DATA' in os.environ:
         library_paths = ('libsecp256k1.so',)
     else:  # desktop Linux and similar
-        library_paths = (os.path.join(os.path.dirname(__file__), 'libsecp256k1.so.0'),
-                         'libsecp256k1.so.0')
+        library_paths = (os.path.join(os.path.dirname(__file__), 'libsecp256k1.so'),
+                         'libsecp256k1.so')
 
     exceptions = []
     secp256k1 = None
