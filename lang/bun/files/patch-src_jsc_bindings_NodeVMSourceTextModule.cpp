-- Fix build with older JavaScriptCore: setStatus -> status.

--- src/jsc/bindings/NodeVMSourceTextModule.cpp.orig	2026-05-14 00:23:23 UTC
+++ src/jsc/bindings/NodeVMSourceTextModule.cpp
@@ -352,7 +352,7 @@ JSValue NodeVMSourceTextModule::link(JSGlobalObject* g
             // Unlinked for the whole graph), so do it for each dependency as
             // we wire it in.
             if (auto* cyclic = dynamicDowncast<JSC::CyclicModuleRecord>(resolvedRecord); cyclic && cyclic->status() == JSC::CyclicModuleRecord::Status::New)
-                cyclic->setStatus(JSC::CyclicModuleRecord::Status::Unlinked);
+                cyclic->status(JSC::CyclicModuleRecord::Status::Unlinked);
 
             // specifiers/moduleNatives were built from requestedModules() in
             // [kLink], so the indices line up — pass the original ModuleRequest
@@ -384,7 +384,7 @@ JSValue NodeVMSourceTextModule::link(JSGlobalObject* g
     // innerModuleLinking now would walk into a record whose loadedModules()
     // are still empty (cyclic case).
     if (record->status() == JSC::CyclicModuleRecord::Status::New)
-        record->setStatus(JSC::CyclicModuleRecord::Status::Unlinked);
+        record->status(JSC::CyclicModuleRecord::Status::Unlinked);
 
     UNUSED_PARAM(scriptFetcher);
     status(Status::Linked);
