--- setup_lz4.py.orig	2017-12-30 09:14:25 UTC
+++ setup_lz4.py
@@ -24,7 +24,7 @@ def lz4_system_prefix(prefixes):
     for prefix in prefixes:
         filename = os.path.join(prefix, 'include', 'lz4.h')
         if os.path.exists(filename):
-            with open(filename, 'r') as fd:
+            with open(filename, 'r', encoding='utf-8') as fd:
                 if 'LZ4_compress_default' in fd.read():  # requires lz4 >= 1.7.0 (r129)
                     return prefix
 
