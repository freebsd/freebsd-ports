--- signer/src/daemon/signercommands.h.orig	2020-02-10 17:25:11 UTC
+++ signer/src/daemon/signercommands.h
@@ -35,7 +35,7 @@
 #include "config.h"
 #include "cmdhandler.h"
 
-struct cmd_func_block** signercommands;
+extern struct cmd_func_block** signercommands;
 
 extern engine_type* getglobalcontext(cmdhandler_ctx_type*);
 
