--- enforcer/src/keystate/rollover_list_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/keystate/rollover_list_cmd.h
@@ -30,6 +30,6 @@
 #ifndef _ROLLOVER_LIST_CMD_H_
 #define _ROLLOVER_LIST_CMD_H_
 
-struct cmd_func_block rollover_list_funcblock;
+extern struct cmd_func_block rollover_list_funcblock;
 
 #endif /* _ROLLOVER_LIST_CMD_H_ */
