--- odoo/__init__.py.orig	2025-07-19 20:57:46 UTC
+++ odoo/__init__.py
@@ -74,7 +74,7 @@ if hasattr(time, 'tzset'):
 # because some pdf won't fit into allocated memory
 # https://docs.python.org/3/library/zlib.html#zlib.decompressobj
 # ----------------------------------------------------------
-import PyPDF2
+import pypdf as PyPDF2
 
 try:
     import zlib
@@ -83,7 +83,7 @@ try:
         zobj = zlib.decompressobj()
         return zobj.decompress(data)
 
-    import PyPDF2.filters  # needed after PyPDF2 2.0.0 and before 2.11.0
+    import pypdf.filters  # needed after PyPDF2 2.0.0 and before 2.11.0
     PyPDF2.filters.decompress = _decompress
 except ImportError:
     pass # no fix required
