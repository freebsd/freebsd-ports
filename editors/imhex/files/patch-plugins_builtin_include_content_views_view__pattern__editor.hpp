--- plugins/builtin/include/content/views/view_pattern_editor.hpp.orig	2023-06-24 14:40:57 UTC
+++ plugins/builtin/include/content/views/view_pattern_editor.hpp
@@ -19,6 +19,7 @@
 #include <thread>
 #include <vector>
 #include <functional>
+#include <hpx/functional.hpp>
 
 #include <TextEditor.h>
 
@@ -151,7 +152,7 @@ namespace hex::plugin::builtin {
         bool m_syncPatternSourceCode = false;
         bool m_autoLoadPatterns = true;
 
-        std::map<prv::Provider*, std::move_only_function<void()>> m_sectionWindowDrawer;
+        std::map<prv::Provider*, hpx::move_only_function<void()>> m_sectionWindowDrawer;
 
         ui::HexEditor m_sectionHexEditor;
 
