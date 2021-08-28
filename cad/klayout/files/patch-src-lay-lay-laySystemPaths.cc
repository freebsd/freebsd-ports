--- src/lay/lay/laySystemPaths.cc.orig	2021-08-28 18:02:22 UTC
+++ src/lay/lay/laySystemPaths.cc
@@ -26,6 +26,8 @@
 #include "tlString.h"
 #include "tlEnv.h"
 
+#include "laySystemPathsDefaults.h"
+
 #include <QDir>
 #include <QFileInfo>
 #include <QCoreApplication>
@@ -109,6 +111,7 @@ get_klayout_path ()
     } else {
       klayout_path.push_back (tl::get_inst_path ());
     }
+    split_path (PLUGINS_BASEDIR, klayout_path);
 
     return klayout_path;
 
