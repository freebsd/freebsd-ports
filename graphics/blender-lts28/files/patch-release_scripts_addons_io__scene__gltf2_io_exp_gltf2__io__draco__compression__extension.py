--- release/scripts/addons/io_scene_gltf2/io/exp/gltf2_io_draco_compression_extension.py.orig	2019-07-31 06:38:16 UTC
+++ release/scripts/addons/io_scene_gltf2/io/exp/gltf2_io_draco_compression_extension.py
@@ -13,6 +13,7 @@
 # limitations under the License.
 
 import bpy
+import site
 import sys
 from ctypes import *
 from pathlib import Path
@@ -35,7 +36,7 @@ def dll_path() -> Path:
         'darwin': blender_root.parent/'Resources'/python_lib/'python3.7'/'site-packages'/'lib{}.dylib'.format(lib_name)
     }
 
-    path = paths.get(sys.platform)
+    path = Path('{}/lib{}.so'.format(site.getsitepackages()[0], lib_name))
     return path if path is not None else ''
 
 
