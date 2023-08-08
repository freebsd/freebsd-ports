--- src/lay/lay/laySystemPaths.cc.orig	2022-12-22 22:17:08 UTC
+++ src/lay/lay/laySystemPaths.cc
@@ -26,6 +26,8 @@
 #include "tlString.h"
 #include "tlEnv.h"
 
+#include "laySystemPathsDefaults.h"
+
 #include <QDir>
 #include <QFileInfo>
 #include <QCoreApplication>
@@ -121,6 +123,7 @@ get_klayout_path ()
     } else {
       klayout_path.push_back (tl::get_inst_path ());
     }
+    split_path (PLUGINS_BASEDIR, klayout_path);
 
     return klayout_path;
 
