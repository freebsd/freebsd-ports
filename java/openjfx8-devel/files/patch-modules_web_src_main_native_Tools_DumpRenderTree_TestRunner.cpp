--- modules/web/src/main/native/Tools/DumpRenderTree/TestRunner.cpp.orig	2018-12-10 16:30:22 UTC
+++ modules/web/src/main/native/Tools/DumpRenderTree/TestRunner.cpp
@@ -2415,7 +2415,7 @@ void TestRunner::runUIScript(JSContextRef context, JSS
     if (!m_UIScriptContext)
         m_UIScriptContext = std::make_unique<WTR::UIScriptContext>(*this);
 
-    String scriptString(JSStringGetCharactersPtr(script), JSStringGetLength(script));
+    String scriptString(reinterpret_cast<const UChar*>(JSStringGetCharactersPtr(script)), JSStringGetLength(script));
     m_UIScriptContext->runUIScript(scriptString, callbackID);
 }
 
