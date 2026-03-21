--- src/espeakng_loader/__init__.py.orig	2026-03-16 18:06:28 UTC
+++ src/espeakng_loader/__init__.py
@@ -4,15 +4,10 @@ def get_library_path():
 import os
 
 def get_library_path():
-    ext = ".dll" if platform.system() == "Windows" else ".so" if platform.system() == "Linux" else ".dylib"
-    lib_name = "espeak-ng" + ext if platform.system() == "Windows" else 'libespeak-ng' + ext
-    return str(Path(__file__).parent / lib_name)
+    return f"%%PREFIX%%/lib/libespeak-ng.so"
 
 def get_data_path():
-    data_path = Path(__file__).parent / 'espeak-ng-data'
-    if not data_path.exists():
-        raise RuntimeError(f'data path not exists at {data_path}')
-    return str(data_path)
+    return f"%%PREFIX%%/share/espeak-ng/espeak-ng-data"
 
 def load_library():
     """
