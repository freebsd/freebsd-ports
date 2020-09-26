--- enforcer/src/keystate/keystate_import_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/keystate/keystate_import_cmd.h
@@ -28,7 +28,7 @@
 #ifndef _KEYSTATE_IMPORT_CMD_H_
 #define _KEYSTATE_IMPORT_CMD_H_
 
-struct cmd_func_block key_import_funcblock;
+extern struct cmd_func_block key_import_funcblock;
 
 #endif /* _KEYSTATE_IMPORT_CMD_H_ */
 
