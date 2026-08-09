--- gcc/config/rs6000/rs6000.cc.orig
+++ gcc/config/rs6000/rs6000.cc
@@ -28283,6 +28283,7 @@
 
   /* Map long double built-in functions if long double is IEEE 128-bit.  */
   if (TARGET_FLOAT128_TYPE && TARGET_IEEEQUAD && TARGET_LONG_DOUBLE_128
+      && glibc_supports_ieee_128bit ()
       && TREE_CODE (decl) == FUNCTION_DECL
       && DECL_IS_UNDECLARED_BUILTIN (decl)
       && DECL_BUILT_IN_CLASS (decl) == BUILT_IN_NORMAL)
