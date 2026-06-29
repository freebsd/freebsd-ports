--- swift/lib/ClangImporter/ClangImporter.cpp.orig	2024-06-06 04:26:30 UTC
+++ swift/lib/ClangImporter/ClangImporter.cpp
@@ -4143,9 +4143,22 @@ void ClangModuleUnit::getImportedModulesForLookup(
   for (auto importMod : topLevelImported) {
     auto wrapper = owner.getWrapperForModule(importMod);
 
-    auto actualMod = wrapper->getOverlayModule();
-    if (!actualMod || actualMod == topLevelOverlay)
+    ModuleDecl *actualMod = nullptr;
+    if (owner.SwiftContext.LangOpts.EnableCXXInterop && topLevel &&
+        isCxxStdModule(topLevel) && wrapper->clangModule &&
+        isCxxStdModule(wrapper->clangModule)) {
+      // The CxxStdlib overlay re-exports the clang module std, which in recent
+      // libc++ versions re-exports top-level modules for different std headers
+      // (std_string, std_vector, etc). The overlay module for each of the std
+      // modules is the CxxStdlib module itself. Make sure we return the actual
+      // clang modules (std_xyz) as transitive dependencies instead of just
+      // CxxStdlib itself.
       actualMod = wrapper->getParentModule();
+    } else {
+      actualMod = wrapper->getOverlayModule();
+      if (!actualMod || actualMod == topLevelOverlay)
+        actualMod = wrapper->getParentModule();
+    }
 
     assert(actualMod && "Missing imported overlay");
     imports.push_back({ImportPath::Access(), actualMod});
