--- enforcer/src/daemon/enforcercommands.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/daemon/enforcercommands.h
@@ -37,7 +37,7 @@
 #include "engine.h"
 #include "db/db_connection.h"
 
-struct cmd_func_block** enforcercommands;
+extern struct cmd_func_block** enforcercommands;
 
 engine_type* getglobalcontext(cmdhandler_ctx_type*);
 db_connection_t* getconnectioncontext(cmdhandler_ctx_type*);
