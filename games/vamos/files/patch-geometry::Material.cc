--- geometry/Material.cc.orig	Mon May 12 04:50:28 2003
+++ geometry/Material.cc	Thu Jul 24 01:30:44 2003
@@ -17,6 +17,8 @@
 
 #include <vamos/geometry/Material.h>
 #include <vamos/geometry/Conversions.h>
+
+#include <cassert>
 #include <iostream>
 
 Vamos_Geometry::Material::
