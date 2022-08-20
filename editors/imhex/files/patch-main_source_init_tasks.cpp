--- main/source/init/tasks.cpp.orig	2022-08-20 13:59:16 UTC
+++ main/source/init/tasks.cpp
@@ -4,6 +4,7 @@
 #include <imgui_freetype.h>
 
 #include <hex/api/content_registry.hpp>
+#include <hex/api/project_file_manager.hpp>
 #include <hex/ui/view.hpp>
 #include <hex/helpers/net.hpp>
 #include <hex/helpers/fs.hpp>
@@ -228,6 +229,9 @@ namespace hex::init {
                 delete visualizer;
             visualizers.clear();
         }
+
+        ProjectFile::getHandlers().clear();
+        ProjectFile::getProviderHandlers().clear();
 
         return true;
     }
