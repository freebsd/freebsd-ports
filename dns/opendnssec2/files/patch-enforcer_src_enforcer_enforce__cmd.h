--- enforcer/src/enforcer/enforce_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/enforcer/enforce_cmd.h
@@ -30,6 +30,6 @@
 #ifndef _ENFORCER_ENFORCE_CMD_H_
 #define _ENFORCER_ENFORCE_CMD_H_
 
-struct cmd_func_block enforce_funcblock;
+extern struct cmd_func_block enforce_funcblock;
 
 #endif /* _ENFORCER_ENFORCE_CMD_H_ */
