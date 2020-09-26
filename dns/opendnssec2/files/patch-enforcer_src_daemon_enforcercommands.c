--- enforcer/src/daemon/enforcercommands.c.orig	2020-02-10 17:25:12 UTC
+++ enforcer/src/daemon/enforcercommands.c
@@ -98,7 +98,7 @@ static struct cmd_func_block* enforcecommands[] = {
         NULL
 };
 
-struct cmd_func_block** enforcercommands = enforcecommands;
+extern struct cmd_func_block** enforcercommands = enforcecommands;
 
 engine_type*
 getglobalcontext(cmdhandler_ctx_type* context)
