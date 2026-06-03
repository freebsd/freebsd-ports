-- Fix build with older JavaScriptCore: setHasTLA -> hasTLA.

--- src/jsc/bindings/BunAnalyzeTranspiledModule.cpp.orig	2026-05-14 00:23:23 UTC
+++ src/jsc/bindings/BunAnalyzeTranspiledModule.cpp
@@ -73,7 +73,7 @@ extern "C" JSModuleRecord* JSC_JSModuleRecord__create(
 {
     JSModuleRecord* result = JSModuleRecord::create(globalObject, vm, globalObject->moduleRecordStructure(), *moduleKey, sourceCode, declaredVariables, lexicalVariables, hasImportMeta ? ImportMetaFeature : 0);
     result->m_isTypeScript = isTypescript;
-    result->setHasTLA(hasTLA);
+    result->hasTLA(hasTLA);
     return result;
 }
 
