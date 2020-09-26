--- enforcer/src/enforcer/update_conf_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/enforcer/update_conf_cmd.h
@@ -29,6 +29,6 @@
 #ifndef UPDATE_CONF_CMD_H_
 #define UPDATE_CONF_CMD_H_
 
-struct cmd_func_block update_conf_funcblock;
+extern struct cmd_func_block update_conf_funcblock;
 
 #endif /* UPDATE_CONF_CMD_H_ */
