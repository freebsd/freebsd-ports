--- scripts/addons_core/io_scene_gltf2/io/com/draco.py.orig	2026-04-17 10:30:36 UTC
+++ scripts/addons_core/io_scene_gltf2/io/com/draco.py
@@ -14,11 +14,7 @@ def dll_path() -> Path:
     :return: library path.
     """
     lib_name = 'extern_draco'
-    library_name = {
-        'win32': '{}.dll'.format(lib_name),
-        'linux': 'lib{}.so'.format(lib_name),
-        'darwin': 'lib{}.dylib'.format(lib_name)
-    }.get(sys.platform)
+    library_name = 'lib{}.so'.format(lib_name)
 
     path = os.path.dirname(sys.modules['io_scene_gltf2'].__file__)
     if path is not None:
