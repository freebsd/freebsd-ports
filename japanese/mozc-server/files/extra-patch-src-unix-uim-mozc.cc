--- src/unix/uim/mozc.cc.orig	2015-07-15 10:04:31.000000000 +0900
+++ src/unix/uim/mozc.cc	2019-03-04 19:35:14.711403000 +0900
@@ -48,6 +48,7 @@
 # include "plugin.h"
 #endif
 
+#include "base/init_mozc.h"
 #include "base/port.h"
 #include "base/util.h"
 #include "protocol/config.pb.h"
@@ -902,7 +903,7 @@
   int i;
 
   for (i = 0; key_tab[i].key; i++)
-    key_map.insert(make_pair(key_tab[i].str, key_tab[i].key));
+    key_map.insert(std::make_pair(key_tab[i].str, key_tab[i].key));
 }
 
 static uim_lisp
@@ -1196,7 +1197,7 @@
   argv[0] = (char *)name;
   argv[1] =  NULL;
 
-  InitGoogle((const char *)argv[0], &argc, (char ***)&argv, true);
+  mozc::InitMozc((const char *)argv[0], &argc, (char ***)&argv, true);
   mozc::uim::install_keymap();
 }
 
