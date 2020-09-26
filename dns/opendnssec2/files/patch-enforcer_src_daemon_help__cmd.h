--- enforcer/src/daemon/help_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/daemon/help_cmd.h
@@ -29,6 +29,6 @@
 #ifndef _HELP_CMD_H_
 #define _HELP_CMD_H_
 
-struct cmd_func_block help_funcblock;
+extern struct cmd_func_block help_funcblock;
 
 #endif /* _HELP_CMD_H_ */
