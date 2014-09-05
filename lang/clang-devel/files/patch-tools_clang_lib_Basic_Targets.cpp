
$FreeBSD$

--- tools/clang/lib/Basic/Targets.cpp.orig
+++ tools/clang/lib/Basic/Targets.cpp
@@ -5723,6 +5723,7 @@
     LongDoubleWidth = LongDoubleAlign = 128;
     LongDoubleFormat = &llvm::APFloat::IEEEquad;
     if (getTriple().getOS() == llvm::Triple::FreeBSD) {
+      IntMaxType = SignedLong;
       LongDoubleWidth = LongDoubleAlign = 64;
       LongDoubleFormat = &llvm::APFloat::IEEEdouble;
     }
