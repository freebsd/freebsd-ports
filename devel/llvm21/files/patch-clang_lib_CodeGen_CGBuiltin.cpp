--- clang/lib/CodeGen/CGBuiltin.cpp.orig
+++ clang/lib/CodeGen/CGBuiltin.cpp
@@ -228,7 +228,7 @@
   else {
     // TODO: This mutation should also be applied to other targets other than
     // PPC, after backend supports IEEE 128-bit style libcalls.
-    if (getTriple().isPPC64() &&
+    if (getTriple().isPPC64() && !getTriple().isOSFreeBSD() &&
         &getTarget().getLongDoubleFormat() == &llvm::APFloat::IEEEquad() &&
         F128Builtins.contains(BuiltinID))
       Name = F128Builtins[BuiltinID];
@@ -2601,6 +2601,7 @@
   // TODO: This mutation should also be applied to other targets other than PPC,
   // after backend supports IEEE 128-bit style libcalls.
   if (getTarget().getTriple().isPPC64() &&
+      !getTarget().getTriple().isOSFreeBSD() &&
       &getTarget().getLongDoubleFormat() == &llvm::APFloat::IEEEquad())
     BuiltinID = mutateLongDoubleBuiltin(BuiltinID);
 
