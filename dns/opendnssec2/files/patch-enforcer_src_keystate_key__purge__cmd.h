--- enforcer/src/keystate/key_purge_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/keystate/key_purge_cmd.h
@@ -1,7 +1,7 @@
 #ifndef _KEYSTATE_KEY_PURGE_CMD_H_
 #define _KEYSTATE_KEY_PURGE_CMD_H_
 
-struct cmd_func_block key_purge_funcblock;
+extern struct cmd_func_block key_purge_funcblock;
 
 #endif /* _KEYSTATE_KEY_PURGE_CMD_H_ */
 
