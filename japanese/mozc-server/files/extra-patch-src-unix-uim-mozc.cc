--- src/unix/uim/mozc.cc.orig	2016-05-11 00:39:29.009401000 +0900
+++ src/unix/uim/mozc.cc	2016-05-11 00:40:58.320083000 +0900
@@ -48,6 +48,7 @@
 # include "plugin.h"
 #endif
 
+#include "base/init_mozc.h"
 #include "base/port.h"
 #include "base/util.h"
 #include "protocol/config.pb.h"
@@ -1196,7 +1197,7 @@
   argv[0] = (char *)name;
   argv[1] =  NULL;
 
-  InitGoogle((const char *)argv[0], &argc, (char ***)&argv, true);
+  mozc::InitMozc((const char *)argv[0], &argc, (char ***)&argv, true);
   mozc::uim::install_keymap();
 }
 
