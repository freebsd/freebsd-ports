--- src/libslic3r/MeshBoolean.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/MeshBoolean.cpp
@@ -10,6 +10,8 @@
 
 #undef PI
 
+#include <boost/next_prior.hpp>
+
 // Include igl first. It defines "L" macro which then clashes with our localization
 #include <igl/copyleft/cgal/mesh_boolean.h> // IWYU pragma: keep
 #include <igl/MeshBooleanType.h>
