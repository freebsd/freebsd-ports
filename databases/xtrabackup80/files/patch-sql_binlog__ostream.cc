--- sql/binlog_ostream.cc.orig	2023-11-24 10:33:10 UTC
+++ sql/binlog_ostream.cc
@@ -239,7 +239,7 @@ bool IO_CACHE_binlog_cache_storage::setup_ciphers_pass
 
   /* Generate password, it is a random string. */
   if (my_rand_buffer(password, sizeof(password))) return true;
-  password_str.append(password, sizeof(password));
+  password_str.insert(password_str.end(), password, password + sizeof(password));
 
   m_io_cache.m_encryptor->close();
   m_io_cache.m_decryptor->close();
