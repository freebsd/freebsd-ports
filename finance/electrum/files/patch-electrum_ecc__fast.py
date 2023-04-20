--- electrum/ecc_fast.py.orig	2023-04-20 06:44:28 UTC
+++ electrum/ecc_fast.py
@@ -43,6 +43,8 @@ def load_library():
         libnames = ['libsecp256k1-1.dll', 'libsecp256k1-0.dll', ]
     elif 'ANDROID_DATA' in os.environ:
         libnames = ['libsecp256k1.so', ]
+    elif 'freebsd' in sys.platform:
+        libnames = ['libsecp256k1.so', ]
     else:  # desktop Linux and similar
         libnames = ['libsecp256k1.so.1', 'libsecp256k1.so.0', ]
     library_paths = []
