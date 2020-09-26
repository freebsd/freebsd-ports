--- enforcer/src/keystate/keystate_list_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/keystate/keystate_list_cmd.h
@@ -32,7 +32,7 @@
 
 #include "db/key_data.h"
 
-struct cmd_func_block key_list_funcblock;
+extern struct cmd_func_block key_list_funcblock;
 
 const char* map_keystate(key_data_t *key);
 
