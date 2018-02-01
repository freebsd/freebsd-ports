--- modules/web/src/main/native/Tools/DumpRenderTree/TestRunner.cpp.orig	2018-01-16 01:40:56 UTC
+++ modules/web/src/main/native/Tools/DumpRenderTree/TestRunner.cpp
@@ -2400,7 +2400,7 @@ void TestRunner::runUIScript(JSContextRef context, JSS
     if (!m_UIScriptContext)
         m_UIScriptContext = std::make_unique<WTR::UIScriptContext>(*this);
 
-    String scriptString(JSStringGetCharactersPtr(script), JSStringGetLength(script));
+    String scriptString(reinterpret_cast<const UChar*>(JSStringGetCharactersPtr(script)), JSStringGetLength(script));
     m_UIScriptContext->runUIScript(scriptString, callbackID);
 }
 
