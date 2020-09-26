--- enforcer/src/keystate/keystate_ds_seen_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/keystate/keystate_ds_seen_cmd.h
@@ -32,6 +32,6 @@
 
 #include "daemon/engine.h"
 
-struct cmd_func_block key_ds_seen_funcblock;
+extern struct cmd_func_block key_ds_seen_funcblock;
 
 #endif /* _KEYSTATE_DS_SEEN_CMD_H_ */
