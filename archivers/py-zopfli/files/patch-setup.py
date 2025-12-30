--- setup.py.orig	2025-11-07 16:49:52 UTC
+++ setup.py
@@ -57,6 +57,7 @@ if prefer_system_zopfli:
         "sources": [
             "src/zopflimodule.c",
         ],
+        "include_dirs": ["%%LOCALBASE%%/include/zopfli", "%%LOCALBASE%%/include/zopflipng"],
         "libraries": ["zopfli", "zopflipng"],
         "define_macros": system_define_macros,
     }
