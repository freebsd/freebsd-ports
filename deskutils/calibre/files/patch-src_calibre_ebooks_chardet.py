--- src/calibre/ebooks/chardet.py.orig	2023-01-17 15:04:24 UTC
+++ src/calibre/ebooks/chardet.py
@@ -109,7 +109,7 @@ def detect(bytestring):
         from calibre_extensions.uchardet import detect as implementation
     except ImportError:
         # People running from source without updated binaries
-        from cchardet import detect as cdi
+        from charset_normalizer import detect as cdi
 
         def implementation(x):
             return cdi(x).get('encoding') or ''
