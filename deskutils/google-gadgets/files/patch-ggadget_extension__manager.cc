
$FreeBSD$

--- ggadget/extension_manager.cc.orig
+++ ggadget/extension_manager.cc
@@ -26,6 +26,12 @@
 #include "common.h"
 #include "extension_manager.h"
 
+#if __GNUC__ < 4
+#define CAST_HACK(x) (x)
+#else
+#define CAST_HACK(x) reinterpret_cast<x>
+#endif
+
 namespace ggadget {
 
 ElementExtensionRegister::ElementExtensionRegister(ElementFactory *factory)
@@ -35,7 +41,7 @@
 bool ElementExtensionRegister::RegisterExtension(const Module *extension) {
   ASSERT(extension);
   RegisterElementExtensionFunc func =
-      reinterpret_cast<RegisterElementExtensionFunc>(
+    CAST_HACK(RegisterElementExtensionFunc)(
           extension->GetSymbol(kElementExtensionSymbolName));
 
   return func ? func(factory_) : false;
@@ -48,7 +54,7 @@
 bool ScriptExtensionRegister::RegisterExtension(const Module *extension) {
   ASSERT(extension);
   RegisterScriptExtensionFunc func =
-      reinterpret_cast<RegisterScriptExtensionFunc>(
+    CAST_HACK(RegisterScriptExtensionFunc)(
           extension->GetSymbol(kScriptExtensionSymbolName));
 
   return func ? func(context_) : false;
@@ -64,7 +70,7 @@
 bool FrameworkExtensionRegister::RegisterExtension(const Module *extension) {
   ASSERT(extension);
   RegisterFrameworkExtensionFunc func =
-      reinterpret_cast<RegisterFrameworkExtensionFunc>(
+      CAST_HACK(RegisterFrameworkExtensionFunc)(
           extension->GetSymbol(kFrameworkExtensionSymbolName));
 
   return func ? func(framework_, gadget_) : false;
@@ -79,7 +85,7 @@
 ScriptRuntimeExtensionRegister::RegisterExtension(const Module *extension) {
   ASSERT(extension);
   RegisterScriptRuntimeExtensionFunc func =
-      reinterpret_cast<RegisterScriptRuntimeExtensionFunc>(
+      CAST_HACK(RegisterScriptRuntimeExtensionFunc)(
           extension->GetSymbol(kScriptRuntimeExtensionSymbolName));
 
   return func ? func(manager_) : false;
