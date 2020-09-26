--- enforcer/src/daemon/queue_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/daemon/queue_cmd.h
@@ -29,7 +29,7 @@
 #ifndef _QUEUE_CMD_H_
 #define _QUEUE_CMD_H_
 
-struct cmd_func_block queue_funcblock;
-struct cmd_func_block flush_funcblock;
+extern struct cmd_func_block queue_funcblock;
+extern struct cmd_func_block flush_funcblock;
 
 #endif /* _QUEUE_CMD_H_ */
