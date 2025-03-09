--- src/libslic3r/MeshBoolean.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/libslic3r/MeshBoolean.cpp
@@ -10,6 +10,8 @@
 
 #undef PI
 
+#include <boost/next_prior.hpp>
+
 // Include igl first. It defines "L" macro which then clashes with our localization
 #include <igl/copyleft/cgal/mesh_boolean.h> // IWYU pragma: keep
 #include <igl/MeshBooleanType.h>
