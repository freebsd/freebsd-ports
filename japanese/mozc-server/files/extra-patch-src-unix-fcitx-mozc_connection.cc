--- src/unix/fcitx/mozc_connection.cc.bak	2015-07-13 04:37:03.716883000 +0900
+++ src/unix/fcitx/mozc_connection.cc	2015-07-13 04:37:03.789664000 +0900
@@ -36,7 +36,7 @@
 #include "base/util.h"
 #include "client/client.h"
 #include "ipc/ipc.h"
-#include "session/commands.pb.h"
+#include "protocol/commands.pb.h"
 #include "session/ime_switch_util.h"
 #include "unix/fcitx/fcitx_key_event_handler.h"
 #include "unix/fcitx/surrounding_text_util.h"
