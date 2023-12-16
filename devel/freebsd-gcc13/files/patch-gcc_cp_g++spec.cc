--- gcc/cp/g++spec.cc.orig	2023-05-08 12:14:39 UTC
+++ gcc/cp/g++spec.cc
@@ -95,7 +95,7 @@ lang_specific_driver (struct cl_decoded_option **in_de
   int library = 0;
 
   /* Which c++ runtime library to link.  */
-  stdcxxlib_kind which_library = USE_LIBSTDCXX;
+  stdcxxlib_kind which_library = USE_LIBCXX;
 
   /* The number of arguments being added to what's in argv, other than
      libraries.  We use this to track the number of times we've inserted
