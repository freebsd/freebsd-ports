--- src/appleseed.studio/mainwindow/project/texturecollectionitem.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed.studio/mainwindow/project/texturecollectionitem.cpp
@@ -108,11 +108,15 @@ namespace
         texture_params.insert("filename", path);
         texture_params.insert("color_space", "srgb");
 
+        // Workaround for GCC 4.2.1: we cannot construct object in .create() below
+        // because GCC will attempt to invoke copy ctor which is private of course.
+        SearchPaths paths;
+
         return
             DiskTexture2dFactory().create(
                 texture_name.c_str(),
                 texture_params,
-                SearchPaths());
+                paths);
     }
 
     auto_release_ptr<TextureInstance> create_texture_instance(const string& texture_name)
