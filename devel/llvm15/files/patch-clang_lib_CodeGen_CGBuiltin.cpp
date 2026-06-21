--- clang/lib/CodeGen/CGBuiltin.cpp.orig
+++ clang/lib/CodeGen/CGBuiltin.cpp
@@ -118,7 +118,7 @@
   else {
     // TODO: This mutation should also be applied to other targets other than
     // PPC, after backend supports IEEE 128-bit style libcalls.
-    if (getTriple().isPPC64() &&
+    if (getTriple().isPPC64() && !getTriple().isOSFreeBSD() &&
         &getTarget().getLongDoubleFormat() == &llvm::APFloat::IEEEquad() &&
         F128Builtins.find(BuiltinID) != F128Builtins.end())
       Name = F128Builtins[BuiltinID];
@@ -2189,6 +2189,7 @@
   // TODO: This mutation should also be applied to other targets other than PPC,
   // after backend supports IEEE 128-bit style libcalls.
   if (getTarget().getTriple().isPPC64() &&
+      !getTarget().getTriple().isOSFreeBSD() &&
       &getTarget().getLongDoubleFormat() == &llvm::APFloat::IEEEquad())
     BuiltinID = mutateLongDoubleBuiltin(BuiltinID);
 
