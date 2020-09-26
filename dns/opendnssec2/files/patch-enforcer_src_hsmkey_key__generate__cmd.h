--- enforcer/src/hsmkey/key_generate_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/hsmkey/key_generate_cmd.h
@@ -29,6 +29,6 @@
 #ifndef HSMKEY_KEY_GENERATE_CMD_H_
 #define HSMKEY_KEY_GENERATE_CMD_H_
 
-struct cmd_func_block key_generate_funcblock;
+extern struct cmd_func_block key_generate_funcblock;
 
 #endif /* HSMKEY_KEY_GENERATE_CMD_H_ */
