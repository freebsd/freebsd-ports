--- src/core/minbif.cpp.orig
+++ src/core/minbif.cpp
@@ -17,7 +17,7 @@
  */
 
 #include <cerrno>
-#include <stdlib.h>
+#include <cstdlib>
 #include <iostream>
 #include <fstream>
 #include <cstring>
@@ -239,7 +239,9 @@
 		}
 		sighandler.setApplication(this);
 
+#if ! GLIB_CHECK_VERSION(2, 32, 0)
 		g_thread_init(NULL);
+#endif
 		loop = g_main_new(FALSE);
 		g_main_run(loop);
 
