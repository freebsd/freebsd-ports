
$FreeBSD$

--- tools/clang/lib/Basic/Targets.cpp.orig
+++ tools/clang/lib/Basic/Targets.cpp
@@ -4981,6 +4981,8 @@
     LongDoubleWidth = LongDoubleAlign = 128;
     LongDoubleFormat = &llvm::APFloat::IEEEquad;
     if (getTriple().getOS() == llvm::Triple::FreeBSD) {
+      IntMaxType = SignedLong;
+      UIntMaxType = UnsignedLong;
       LongDoubleWidth = LongDoubleAlign = 64;
       LongDoubleFormat = &llvm::APFloat::IEEEdouble;
     }
