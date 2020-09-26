--- enforcer/src/enforcer/update_repositorylist_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/enforcer/update_repositorylist_cmd.h
@@ -30,6 +30,6 @@
 #ifndef UPDATE_REPOSITORYLIST_CMD_H_
 #define UPDATE_REPOSITORYLIST_CMD_H_
 
-struct cmd_func_block update_repositorylist_funcblock;
+extern struct cmd_func_block update_repositorylist_funcblock;
 
 #endif /* UPDATE_REPOSITORYLIST_CMD_H_ */
