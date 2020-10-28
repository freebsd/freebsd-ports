https://github.com/WebKit/webkit/commit/35a79bf4c2e0ecb4a37e672de347a25254ea0601

* DumpRenderTree/TestRunner.cpp:
(TestRunner::runUIScript):
Manually convert between UChar and UniChar/unichar where needed.


--- modules/javafx.web/src/main/native/Tools/DumpRenderTree/TestRunner.cpp.orig	2020-07-19 19:13:03 UTC
+++ modules/javafx.web/src/main/native/Tools/DumpRenderTree/TestRunner.cpp
@@ -2463,7 +2463,7 @@ void TestRunner::runUIScript(JSContextRef context, JSS
     if (!m_UIScriptContext)
         m_UIScriptContext = makeUniqueWithoutFastMallocCheck<WTR::UIScriptContext>(*this);
 
-    String scriptString(JSStringGetCharactersPtr(script), JSStringGetLength(script));
+    String scriptString(reinterpret_cast<const UChar*>(JSStringGetCharactersPtr(script)), JSStringGetLength(script));
     m_UIScriptContext->runUIScript(scriptString, callbackID);
 }
 
