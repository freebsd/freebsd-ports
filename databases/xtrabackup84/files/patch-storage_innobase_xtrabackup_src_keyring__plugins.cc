--- storage/innobase/xtrabackup/src/keyring_plugins.cc.orig	2024-11-11 11:46:47 UTC
+++ storage/innobase/xtrabackup/src/keyring_plugins.cc
@@ -863,7 +863,7 @@ bool xb_binlog_password_reencrypt(const char *binlog_f
     return (false);
   }
 
-  Key_string file_password(key, Encryption::KEY_LEN);
+  Key_string file_password(key, key + Encryption::KEY_LEN);
   header->encrypt_file_password(file_password);
 
   IO_CACHE_ostream ostream;
