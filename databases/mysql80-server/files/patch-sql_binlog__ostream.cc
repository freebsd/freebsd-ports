--- sql/binlog_ostream.cc.orig	2024-07-12 19:15:25 UTC
+++ sql/binlog_ostream.cc
@@ -240,7 +240,7 @@ bool IO_CACHE_binlog_cache_storage::setup_ciphers_pass
 
   /* Generate password, it is a random string. */
   if (my_rand_buffer(password, sizeof(password))) return true;
-  password_str.append(password, sizeof(password));
+  password_str.insert(password_str.end(), password, password + sizeof(password));
 
   m_io_cache.m_encryptor->close();
   m_io_cache.m_decryptor->close();
