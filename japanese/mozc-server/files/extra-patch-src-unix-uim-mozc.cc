--- src/unix/uim/mozc.cc.orig	2015-07-13 05:03:12.431514000 +0900
+++ src/unix/uim/mozc.cc	2015-07-13 05:03:30.340372000 +0900
@@ -50,8 +50,8 @@
 
 #include "base/port.h"
 #include "base/util.h"
-#include "config/config.pb.h"
-#include "session/commands.pb.h"
+#include "protocol/config.pb.h"
+#include "protocol/commands.pb.h"
 #include "client/client.h"
 #include "unix/uim/key_translator.h"
 
