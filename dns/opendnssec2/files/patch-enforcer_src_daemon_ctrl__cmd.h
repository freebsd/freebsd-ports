--- enforcer/src/daemon/ctrl_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/daemon/ctrl_cmd.h
@@ -29,6 +29,6 @@
 #ifndef _CTRL_CMD_H_
 #define _CTRL_CMD_H_
 
-struct cmd_func_block ctrl_funcblock;
+extern struct cmd_func_block ctrl_funcblock;
 
 #endif /* _CTRL_CMD_H_ */
