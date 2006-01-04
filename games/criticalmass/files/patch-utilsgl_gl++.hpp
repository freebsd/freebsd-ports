--- utilsgl/gl++.hpp.orig	Sat Dec 18 11:41:34 2004
+++ utilsgl/gl++.hpp	Tue Mar 22 14:24:11 2005
@@ -23,6 +23,7 @@
 #endif
 
 #include <GL/gl.h>
+#include <GL/glext.h>
 
 #ifndef GLintptrARB
 # if defined(_WIN64)
