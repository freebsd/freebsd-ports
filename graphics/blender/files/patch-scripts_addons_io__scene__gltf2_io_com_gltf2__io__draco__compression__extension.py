--- scripts/addons/io_scene_gltf2/io/com/gltf2_io_draco_compression_extension.py.orig	2023-02-15 14:57:11 UTC
+++ scripts/addons/io_scene_gltf2/io/com/gltf2_io_draco_compression_extension.py
@@ -33,7 +33,7 @@ def dll_path() -> Path:
         'win32': '{}.dll'.format(lib_name),
         'linux': 'lib{}.so'.format(lib_name),
         'darwin': 'lib{}.dylib'.format(lib_name)
-    }.get(sys.platform)
+    }.get(sys.platform, 'lib{}.so'.format(lib_name))
 
     if path is None or library_name is None:
         print_console('WARNING', 'Unsupported platform {}, Draco mesh compression is unavailable'.format(sys.platform))
