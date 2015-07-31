--- src/unix/fcitx/fcitx_key_event_handler.h.bak	2015-07-13 04:37:03.713712000 +0900
+++ src/unix/fcitx/fcitx_key_event_handler.h	2015-07-13 04:37:03.754663000 +0900
@@ -35,8 +35,8 @@
 #include <memory>
 
 #include "base/port.h"
-#include "config/config.pb.h"
-#include "session/commands.pb.h"
+#include "protocol/config.pb.h"
+#include "protocol/commands.pb.h"
 #include "unix/fcitx/fcitx_key_translator.h"
 
 namespace mozc {
