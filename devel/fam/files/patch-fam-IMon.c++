diff -ruN fam/IMon.c++ fam/IMon.c++
--- fam/IMon.c++	Mon Apr 29 02:26:54 2002
+++ fam/IMon.c++	Sat Jun  8 16:31:07 2002
@@ -34,7 +34,9 @@
 #endif
 #endif
 
-#include <sys/sysmacros.h>
+#if !defined(__FreeBSD__)
+#  include <sys/sysmacros.h>
+#endif
 #include <unistd.h>
 
 #include "Interest.h"
