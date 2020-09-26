--- enforcer/src/hsmkey/backup_hsmkeys_cmd.h.orig	2020-02-10 17:25:11 UTC
+++ enforcer/src/hsmkey/backup_hsmkeys_cmd.h
@@ -30,6 +30,6 @@
 #ifndef _HSMKEY_BACKUP_CMD_H_
 #define _HSMKEY_BACKUP_CMD_H_
 
-struct cmd_func_block backup_funcblock;
+extern struct cmd_func_block backup_funcblock;
 
 #endif /* _HSMKEY_BACKUP_CMD_H_ */
