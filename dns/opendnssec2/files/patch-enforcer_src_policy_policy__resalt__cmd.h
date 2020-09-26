--- enforcer/src/policy/policy_resalt_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/policy/policy_resalt_cmd.h
@@ -30,6 +30,6 @@
 #ifndef _POLICY_POLICY_RESALT_CMD_H_
 #define _POLICY_POLICY_RESALT_CMD_H_
 
-struct cmd_func_block resalt_funcblock;
+extern struct cmd_func_block resalt_funcblock;
 
 #endif /*_POLICY_POLICY_RESALT_CMD_H_*/
