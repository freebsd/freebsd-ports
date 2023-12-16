--- src/calibre/ebooks/chardet.py.orig	2023-12-15 00:57:56 UTC
+++ src/calibre/ebooks/chardet.py
@@ -111,7 +111,7 @@ def detect(bytestring):
         from calibre_extensions.uchardet import detect as implementation
     except ImportError:
         # People running from source without updated binaries
-        from cchardet import detect as cdi
+        from charset_normalizer import detect as cdi
 
         def implementation(x):
             return cdi(x).get('encoding') or ''
