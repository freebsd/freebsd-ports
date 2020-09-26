--- enforcer/src/policy/policy_import_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/policy/policy_import_cmd.h
@@ -30,6 +30,6 @@
 #ifndef _POLICY_POLICY_IMPORT_CMD_H_
 #define _POLICY_POLICY_IMPORT_CMD_H_
 
-struct cmd_func_block policy_import_funcblock;
+extern struct cmd_func_block policy_import_funcblock;
 
 #endif /* _POLICY_POLICY_IMPORT_CMD_H_ */
