--- geometry/Ac3d.cc.orig	Mon Sep 29 11:30:40 2003
+++ geometry/Ac3d.cc	Fri Oct  3 18:35:35 2003
@@ -26,6 +26,8 @@
 #include <cassert>
 #include <iostream>
 #include <cstdlib>
+#include <algorithm>
+#include <functional>
 
 using namespace Vamos_Geometry;
 
@@ -256,7 +258,11 @@
   m_normal [2] = 1.0;
 
   std::istringstream is (type_code);
+#if defined(__GNUC__) && __GNUC__ < 3
+  is.setf (std::ios::hex, std::ios::basefield);
+#else
   is.setf (std::ios_base::hex, std::ios_base::basefield);
+#endif
   int code;
   is >> code;
 
