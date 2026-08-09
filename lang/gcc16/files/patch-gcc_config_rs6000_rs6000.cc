--- gcc/config/rs6000/rs6000.cc.orig	2026-04-30 08:33:20 UTC
+++ gcc/config/rs6000/rs6000.cc
@@ -28608,6 +28608,7 @@ rs6000_mangle_decl_assembler_name (tree decl, tree id)
 
   /* Map long double built-in functions if long double is IEEE 128-bit.  */
   if (TARGET_FLOAT128_TYPE && TARGET_IEEEQUAD && TARGET_LONG_DOUBLE_128
+      && glibc_supports_ieee_128bit ()
       && TREE_CODE (decl) == FUNCTION_DECL
       && DECL_IS_UNDECLARED_BUILTIN (decl)
       && DECL_BUILT_IN_CLASS (decl) == BUILT_IN_NORMAL)
