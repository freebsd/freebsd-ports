--- files/rwregress.cc.orig	Tue Jun 24 21:20:55 2003
+++ files/rwregress.cc	Wed Mar 31 13:39:13 2004
@@ -5,7 +5,9 @@
 
 #include <iostream>
 #include <strstream>
+#if defined(__GNUC__) && __GNUC__ >= 3
 #include <cassert>
+#endif
 #include "utils.h"
 
 using std::cout;
