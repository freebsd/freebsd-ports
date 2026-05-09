--- src/external/GeometricTools/GeometricTools/GTE/Mathematics/BSRational.h.orig	2026-05-09 14:56:37 UTC
+++ src/external/GeometricTools/GeometricTools/GTE/Mathematics/BSRational.h
@@ -993,10 +993,6 @@ namespace std
     {
         return (gte::BSRational<UInteger>)std::tanh((double)x);
     }
-
-    // Type trait that says BSRational is a signed type.
-    template <typename UInteger>
-    struct is_signed<gte::BSRational<UInteger>> : true_type {};
 }
 
 namespace gte
