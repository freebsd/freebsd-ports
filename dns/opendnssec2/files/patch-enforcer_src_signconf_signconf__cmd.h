--- enforcer/src/signconf/signconf_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/signconf/signconf_cmd.h
@@ -30,6 +30,6 @@
 #ifndef _SIGNCONF_SIGNCONF_CMD_H_
 #define _SIGNCONF_SIGNCONF_CMD_H_
 
-struct cmd_func_block signconf_funcblock;
+extern struct cmd_func_block signconf_funcblock;
 
 #endif /* _SIGNCONF_SIGNCONF_CMD_H_ */
