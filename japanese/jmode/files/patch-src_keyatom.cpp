--- src/keyatom.cpp.orig	2003-01-21 14:26:14 UTC
+++ src/keyatom.cpp
@@ -9,6 +9,8 @@
 #  include <alloca.h>
 # endif
 #endif
+#include <stdlib.h>
+#include <string.h>
 
 #include "jmode.h"
 
@@ -275,7 +277,7 @@ read_conf_file()
 			strlen(CONF_DIR)+20);
     fn[0] = 0;
     strcat(fn, homedir);
-    strcat(fn, "/."PACKAGE);
+    strcat(fn, "/." PACKAGE);
     if (read_a_conf_file(fn)) {
 	return ;
     }
