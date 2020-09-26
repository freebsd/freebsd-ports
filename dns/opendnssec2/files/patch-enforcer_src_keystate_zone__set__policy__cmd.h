--- enforcer/src/keystate/zone_set_policy_cmd.h.orig	2020-02-10 17:25:12 UTC
+++ enforcer/src/keystate/zone_set_policy_cmd.h
@@ -29,6 +29,6 @@
 #ifndef _KEYSTATE_ZONE_SET_POLICY_CMD_H_
 #define _KEYSTATE_ZONE_SET_POLICY_CMD_H_
 
-struct cmd_func_block zone_set_policy_funcblock;
+extern struct cmd_func_block zone_set_policy_funcblock;
 
 #endif /* _KEYSTATE_ZONE_SET_POLICY_CMD_H_ */
