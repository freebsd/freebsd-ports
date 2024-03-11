--- src/libslic3r/MeshBoolean.cpp.orig	2024-03-01 11:44:05 UTC
+++ src/libslic3r/MeshBoolean.cpp
@@ -8,6 +8,8 @@
 #include "libslic3r/TryCatchSignal.hpp"
 #undef PI
 
+#include <boost/next_prior.hpp>
+
 // Include igl first. It defines "L" macro which then clashes with our localization
 #include <igl/copyleft/cgal/mesh_boolean.h>
 #undef L
