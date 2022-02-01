--- release/scripts/addons/io_scene_gltf2/io/com/gltf2_io_draco_compression_extension.py.orig	2021-03-24 15:01:52 UTC
+++ release/scripts/addons/io_scene_gltf2/io/com/gltf2_io_draco_compression_extension.py
@@ -44,7 +44,7 @@ def dll_path() -> Path:
         'win32': '{}.dll'.format(lib_name),
         'linux': 'lib{}.so'.format(lib_name),
         'darwin': 'lib{}.dylib'.format(lib_name)
-    }.get(sys.platform)
+    }.get(sys.platform, 'lib{}.so'.format(lib_name))
 
     if path is None or library_name is None:
         print_console('WARNING', 'Unsupported platform {}, Draco mesh compression is unavailable'.format(sys.platform))
