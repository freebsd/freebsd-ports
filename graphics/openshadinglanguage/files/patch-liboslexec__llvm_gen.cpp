--- ./liboslexec/llvm_gen.cpp.orig	2013-07-12 08:31:18.000000000 +0930
+++ ./liboslexec/llvm_gen.cpp	2013-11-03 18:07:25.652119256 +1030
@@ -3310,7 +3310,7 @@
     Symbol& Results = *rop.opargsym (op, 2);
     DASSERT (R.typespec().is_int() && Str.typespec().is_string() &&
              Results.typespec().is_array() &&
-             Results.typespec().simpletype() == TypeDesc::TypeString);
+             Results.typespec().is_string_based());
 
     llvm::Value *args[5];
     args[0] = rop.llvm_load_value (Str);
