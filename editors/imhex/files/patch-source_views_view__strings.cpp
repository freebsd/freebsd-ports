--- source/views/view_strings.cpp.orig	2020-12-06 20:40:57 UTC
+++ source/views/view_strings.cpp
@@ -5,8 +5,6 @@
 
 #include <cstring>
 
-#include <llvm/Demangle/Demangle.h>
-
 using namespace std::literals::string_literals;
 
 namespace hex {
@@ -37,7 +35,7 @@ namespace hex {
             }
             ImGui::Separator();
             if (ImGui::MenuItem("Demangle")) {
-                this->m_demangledName = llvm::demangle(this->m_selectedString);
+                this->m_demangledName = demangle(this->m_selectedString);
                 if (!this->m_demangledName.empty())
                     View::doLater([]{ ImGui::OpenPopup("Demangled Name"); });
             }
