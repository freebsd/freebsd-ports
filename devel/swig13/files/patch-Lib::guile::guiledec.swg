diff -urN ../SWIG1.3a5/Lib/guile/guiledec.swg ./Lib/guile/guiledec.swg
--- ../SWIG1.3a5/Lib/guile/guiledec.swg	Thu Sep 21 16:06:17 2000
+++ ./Lib/guile/guiledec.swg	Tue Feb 27 06:12:33 2001
@@ -78,10 +78,9 @@
   size_t tag;
 } swig_type_info;
 
-#define swig_types_initial swig_types
-
 SWIGSTATIC void
-SWIG_Guile_RegisterTypes (swig_type_info **table);
+SWIG_Guile_RegisterTypes (swig_type_info **table,
+                         swig_type_info **init);
 
 /* Register a new type-mapping with the type-checker.  origtype is the
    original datatype and newtype is an equivalent type.  cast is optional
