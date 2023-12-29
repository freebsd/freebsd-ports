--- src/checks/manuallevel/unexpected-flag-enumerator-value.cpp.orig	2022-01-20 23:18:47 UTC
+++ src/checks/manuallevel/unexpected-flag-enumerator-value.cpp
@@ -61,8 +61,13 @@ static bool isIntentionallyNotPowerOf2(EnumConstantDec
     if (val.isMask() && val.countTrailingOnes() >= MinOnesToQualifyAsMask)
         return true;
 
+#if LLVM_VERSION_MAJOR >= 17
+    if (val.isMask() && val.popcount() >= MinOnesToQualifyAsMask)
+        return true;
+#else
     if (val.isShiftedMask() && val.countPopulation() >= MinOnesToQualifyAsMask)
         return true;
+#endif
 
     if (clazy::contains_lower(en->getName(), "mask"))
         return true;
@@ -158,7 +163,11 @@ void UnexpectedFlagEnumeratorValue::VisitDecl(clang::D
 
     for (EnumConstantDecl* enumerator : enumerators) {
         const auto &initVal = enumerator->getInitVal();
+#if LLVM_VERSION_MAJOR >= 17
+        if (!initVal.isPowerOf2() && !initVal.isZero() && !initVal.isNegative()) {
+#else
         if (!initVal.isPowerOf2() && !initVal.isNullValue() && !initVal.isNegative()) {
+#endif
             if (isIntentionallyNotPowerOf2(enumerator))
                 continue;
             const auto value = enumerator->getInitVal().getLimitedValue();
