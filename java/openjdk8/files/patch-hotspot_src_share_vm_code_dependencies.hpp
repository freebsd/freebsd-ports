--- hotspot/src/share/vm/code/dependencies.hpp.orig	2024-07-27 18:28:39 UTC
+++ hotspot/src/share/vm/code/dependencies.hpp
@@ -170,7 +170,7 @@ class Dependencies: public ResourceObj {
     LG2_TYPE_LIMIT = 4,  // assert(TYPE_LIMIT <= (1<<LG2_TYPE_LIMIT))
 
     // handy categorizations of dependency types:
-    all_types           = ((1 << TYPE_LIMIT) - 1) & ((-1) << FIRST_TYPE),
+    all_types           = ((1 << TYPE_LIMIT) - 1) & ((~0u) << FIRST_TYPE),
 
     non_klass_types     = (1 << call_site_target_value),
     klass_types         = all_types & ~non_klass_types,
