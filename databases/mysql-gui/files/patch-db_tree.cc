--- db_tree.cc.orig	Wed Apr 11 21:12:19 2001
+++ db_tree.cc	Mon Feb  3 02:32:09 2003
@@ -28,6 +28,7 @@
 #endif
 #include <iomanip>
 #include <string>
+#undef Success
 #include <sqlplus.hh>
 #include "client.h"
