--- enforcer/src/enforcer/repositorylist_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/enforcer/repositorylist_cmd.h
@@ -28,6 +28,6 @@
 #ifndef _ENFORCER_REPOSITORYLIST_CMD_H_
 #define _ENFORCER_REPOSITORYLIST_CMD_H_
 
-struct cmd_func_block repositorylist_funcblock;
+extern struct cmd_func_block repositorylist_funcblock;
 
 #endif
