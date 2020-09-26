--- enforcer/src/keystate/keystate_ds_submit_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/keystate/keystate_ds_submit_cmd.h
@@ -30,6 +30,6 @@
 #ifndef _KEYSTATE_DS_SUBMIT_CMD_H_
 #define _KEYSTATE_DS_SUBMIT_CMD_H_
 
-struct cmd_func_block key_ds_submit_funcblock;
+extern struct cmd_func_block key_ds_submit_funcblock;
 
 #endif /* _KEYSTATE_DS_SUBMIT_CMD_H_ */
