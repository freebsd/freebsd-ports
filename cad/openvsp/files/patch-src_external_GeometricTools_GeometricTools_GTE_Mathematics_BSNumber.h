--- src/external/GeometricTools/GeometricTools/GTE/Mathematics/BSNumber.h.orig	2026-05-07 10:33:13 UTC
+++ src/external/GeometricTools/GeometricTools/GTE/Mathematics/BSNumber.h
@@ -1387,9 +1387,6 @@ namespace std
         return (gte::BSNumber<UInteger>)std::tanh((double)x);
     }
 
-    // Type trait that says BSNumber is a signed type.
-    template <typename UInteger>
-    struct is_signed<gte::BSNumber<UInteger>> : true_type {};
 }
 
 namespace gte
