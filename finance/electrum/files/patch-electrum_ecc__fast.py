--- electrum/ecc_fast.py.orig	2024-12-30 13:18:48 UTC
+++ electrum/ecc_fast.py
@@ -39,7 +39,7 @@ def load_library():
 def load_library():
     # note: for a mapping between bitcoin-core/secp256k1 git tags and .so.V libtool version numbers,
     #       see https://github.com/bitcoin-core/secp256k1/pull/1055#issuecomment-1227505189
-    tested_libversions = [2, 1, 0, ]  # try latest version first
+    tested_libversions = [5, 2, 1, 0, ]  # try latest version first
     libnames = []
     if sys.platform == 'darwin':
         for v in tested_libversions:
