--- geometry/Ac3d.cc.orig	Fri Jun 25 01:10:29 2004
+++ geometry/Ac3d.cc	Fri Jun 25 01:11:59 2004
@@ -27,6 +27,8 @@
 #include <cassert>
 #include <iostream>
 #include <cstdlib>
+#include <algorithm>
+#include <functional>
 
 using namespace Vamos_Geometry;
 
@@ -188,7 +190,11 @@
 	m_normal [2] = 1.0;
 
 	std::istringstream is (figure_type_code);
+#if defined(__GNUC__) && __GNUC__ < 3
+	is.setf (std::ios::hex, std::ios::basefield);
+#else
 	is.setf (std::ios_base::hex, std::ios_base::basefield);
+#endif
 	int code;
 	is >> code;
 
