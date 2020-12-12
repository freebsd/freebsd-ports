--- source/views/view_tools.cpp.orig	2020-12-06 20:40:57 UTC
+++ source/views/view_tools.cpp
@@ -7,8 +7,6 @@
 #include "providers/provider.hpp"
 #include "helpers/utils.hpp"
 
-#include <llvm/Demangle/Demangle.h>
-
 namespace hex {
 
     ViewTools::ViewTools(hex::prv::Provider* &provider) : View("Tools"), m_dataProvider(provider) {
@@ -76,7 +74,7 @@ namespace hex {
     void ViewTools::drawDemangler() {
         if (ImGui::CollapsingHeader("Itanium/MSVC demangler")) {
             if (ImGui::InputText("Mangled name", this->m_mangledBuffer, 0xF'FFFF)) {
-                this->m_demangledName = llvm::demangle(this->m_mangledBuffer);
+                this->m_demangledName = demangle(this->m_mangledBuffer);
             }
 
             ImGui::InputText("Demangled name", this->m_demangledName.data(), this->m_demangledName.size(), ImGuiInputTextFlags_ReadOnly);
