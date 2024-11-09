--- modules/javafx.web/src/main/native/Source/JavaScriptCore/llint/LLIntData.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/JavaScriptCore/llint/LLIntData.h
@@ -156,7 +156,7 @@ ALWAYS_INLINE LLIntCode getCodeFunctionPtr(OpcodeID op
 #if COMPILER(MSVC)
     return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).executableAddress());
 #else
-    return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).template executableAddress());
+    return reinterpret_cast<LLIntCode>(getCodePtr<tag>(opcodeID).template executableAddress<>());
 #endif
 }
 
