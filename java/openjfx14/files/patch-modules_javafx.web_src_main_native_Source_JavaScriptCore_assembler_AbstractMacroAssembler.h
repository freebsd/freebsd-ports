--- modules/javafx.web/src/main/native/Source/JavaScriptCore/assembler/AbstractMacroAssembler.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/JavaScriptCore/assembler/AbstractMacroAssembler.h
@@ -920,7 +920,7 @@ class AbstractMacroAssembler : public AbstractMacroAss
     template<PtrTag tag>
     static void repatchCompact(CodeLocationDataLabelCompact<tag> dataLabelCompact, int32_t value)
     {
-        AssemblerType::repatchCompact(dataLabelCompact.template dataLocation(), value);
+        AssemblerType::repatchCompact(dataLabelCompact.template dataLocation<>(), value);
     }
 
     template<PtrTag tag>
