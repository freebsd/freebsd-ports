--- src/unit_types.cpp.orig	2008-11-02 17:39:16.000000000 +0100
+++ src/unit_types.cpp	2008-11-02 17:44:20.000000000 +0100
@@ -1230,6 +1230,10 @@
     ERR_CONFIG << *unit_cfg_ << "\n";
 
     assert(false && "unit type not found");
+    // Appease the compiler on FreeBSD
+    // Unreachable
+    cfg = NULL;
+    return *cfg;
 }
 
 void unit_type_data::unit_type_map_wrapper::build_all(unit_type::BUILD_STATUS status) const
