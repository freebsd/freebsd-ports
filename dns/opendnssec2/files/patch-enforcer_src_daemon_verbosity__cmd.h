--- enforcer/src/daemon/verbosity_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/daemon/verbosity_cmd.h
@@ -29,6 +29,6 @@
 #ifndef _VERBOSITY_CMD_H_
 #define _VERBOSITY_CMD_H_
 
-struct cmd_func_block verbosity_funcblock;
+extern struct cmd_func_block verbosity_funcblock;
 
 #endif /* _VERBOSITY_CMD_H_ */
