--- enforcer/src/keystate/keystate_rollover_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/keystate/keystate_rollover_cmd.h
@@ -30,6 +30,6 @@
 #ifndef _KEYSTATE_ROLLOVER_CMD_H_
 #define _KEYSTATE_ROLLOVER_CMD_H_
 
-struct cmd_func_block key_rollover_funcblock;
+extern struct cmd_func_block key_rollover_funcblock;
 
 #endif /* _KEYSTATE_ROLLOVER_CMD_H_ */
