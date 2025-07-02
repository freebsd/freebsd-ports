--- sql/rpl_log_encryption.cc.orig	2023-11-24 10:33:10 UTC
+++ sql/rpl_log_encryption.cc
@@ -212,7 +212,7 @@ bool Rpl_encryption::recover_master_key() {
         Rpl_encryption_header::seqno_to_key_id(m_master_key_seqno);
     auto master_key =
         get_key(m_master_key.m_id, Rpl_encryption_header::get_key_type());
-    m_master_key.m_value.assign(master_key.second);
+    m_master_key.m_value = master_key.second;
     /* No keyring error */
     if (master_key.first == Keyring_status::KEYRING_ERROR_FETCHING) goto err1;
   }
@@ -289,7 +289,7 @@ bool Rpl_encryption::recover_master_key() {
 
     if (new_master_key.first == Keyring_status::SUCCESS) {
       m_master_key.m_id = new_master_key_id;
-      m_master_key.m_value.assign(new_master_key.second);
+      m_master_key.m_value = new_master_key.second;
       if (new_master_key_seqno.second > m_master_key_seqno &&
           new_master_key_seqno.second > old_master_key_seqno.second) {
         if (m_master_key_seqno > 0) {
@@ -379,8 +379,8 @@ std::pair<Rpl_encryption::Keyring_status, Key_string> 
           reinterpret_cast<unsigned char *>(std::get<1>(tuple));
       first[0] = ~(first[0]);
     });
-    key_str.append(reinterpret_cast<unsigned char *>(std::get<1>(tuple)),
-                   std::get<2>(tuple));
+    auto *first = reinterpret_cast<unsigned char *>(std::get<1>(tuple));
+    key_str.insert(key_str.end(), first, first + std::get<2>(tuple));
     my_free(std::get<1>(tuple));
   }
 
@@ -395,7 +395,7 @@ std::pair<Rpl_encryption::Keyring_status, Key_string> 
   if (pair.first == Keyring_status::SUCCESS) {
     DBUG_EXECUTE_IF("corrupt_replication_encryption_key_size",
                     { pair.second.resize(key_size / 2); });
-    if (pair.second.length() != key_size)
+    if (pair.second.size() != key_size)
       pair.first = Keyring_status::UNEXPECTED_KEY_SIZE;
   }
   return pair;
@@ -449,7 +449,7 @@ bool Rpl_encryption::enable_for_xtrabackup() {
         Rpl_encryption_header::seqno_to_key_id(m_master_key_seqno);
     auto master_key =
         get_key(m_master_key.m_id, Rpl_encryption_header::get_key_type());
-    m_master_key.m_value.assign(master_key.second);
+    m_master_key.m_value = master_key.second;
     /* No keyring error */
     if (master_key.first == Keyring_status::KEYRING_ERROR_FETCHING) res = true;
   }
@@ -770,7 +770,7 @@ Rpl_encryption::get_seqno_from_keyring(std::string key
   auto fetched_key = get_key(key_id, SEQNO_KEY_TYPE, SEQNO_KEY_LENGTH);
   uint32_t seqno = 0;
   if (fetched_key.first == Keyring_status::SUCCESS) {
-    const void *key = fetched_key.second.c_str();
+    const void *key = fetched_key.second.data();
     memcpy(&seqno, key, sizeof(seqno));
     seqno = le32toh(seqno);
   }
@@ -975,7 +975,7 @@ bool Rpl_encryption::generate_master_key_on_keyring(ui
 
   /* Store the generated key as the new master key */
   m_master_key.m_id = key_id;
-  m_master_key.m_value.assign(pair.second);
+  m_master_key.m_value = pair.second;
 
   return false;
 }
@@ -1078,12 +1078,12 @@ bool Rpl_encryption_header_v1::serialize(Basic_ostream
 
   assert(m_encrypted_password.length() == PASSWORD_FIELD_SIZE);
   *ptr++ = ENCRYPTED_FILE_PASSWORD;
-  memcpy(ptr, m_encrypted_password.data(), m_encrypted_password.length());
+  memcpy(ptr, m_encrypted_password.data(), m_encrypted_password.size());
   ptr += PASSWORD_FIELD_SIZE;
 
   assert(m_iv.length() == IV_FIELD_SIZE);
   *ptr++ = IV_FOR_FILE_PASSWORD;
-  memcpy(ptr, m_iv.data(), m_iv.length());
+  memcpy(ptr, m_iv.data(), m_iv.size());
 
   bool res = DBUG_EVALUATE_IF("fail_to_serialize_encryption_header", true,
                               ostream->write(header, HEADER_SIZE));
@@ -1138,13 +1138,13 @@ bool Rpl_encryption_header_v1::deserialize(Basic_istre
             reinterpret_cast<const unsigned char *>(
                 reader.ptr(PASSWORD_FIELD_SIZE));
         if (!reader.has_error())
-          m_encrypted_password.assign(password_ptr, PASSWORD_FIELD_SIZE);
+          m_encrypted_password.assign(password_ptr, password_ptr + PASSWORD_FIELD_SIZE);
         break;
       }
       case IV_FOR_FILE_PASSWORD: {
         const unsigned char *iv_ptr =
             reinterpret_cast<const unsigned char *>(reader.ptr(IV_FIELD_SIZE));
-        if (!reader.has_error()) m_iv.assign(iv_ptr, IV_FIELD_SIZE);
+        if (!reader.has_error()) m_iv.assign(iv_ptr, iv_ptr + IV_FIELD_SIZE);
         break;
       }
       default:
@@ -1204,11 +1204,11 @@ Key_string Rpl_encryption_header_v1::decrypt_file_pass
       unsigned char buffer[Aes_ctr::PASSWORD_LENGTH];
 
       if (my_aes_decrypt(m_encrypted_password.data(),
-                         m_encrypted_password.length(), buffer,
+                         m_encrypted_password.size(), buffer,
                          error_and_key.second.data(),
-                         error_and_key.second.length(), my_aes_256_cbc,
+                         error_and_key.second.size(), my_aes_256_cbc,
                          m_iv.data(), false) != MY_AES_BAD_DATA)
-        file_password.append(buffer, Aes_ctr::PASSWORD_LENGTH);
+        file_password.insert(file_password.end(), buffer, buffer + Aes_ctr::PASSWORD_LENGTH);
     }
   }
 #endif
@@ -1239,16 +1239,16 @@ bool Rpl_encryption_header_v1::encrypt_file_password(K
 
   /* Generate iv, it is a random string. */
   error = my_rand_buffer(iv, Aes_ctr::AES_BLOCK_SIZE);
-  m_iv = Key_string(iv, sizeof(iv));
+  m_iv = Key_string(iv, iv + sizeof(iv));
 
   /* Encrypt password */
   if (!error) {
-    error = (my_aes_encrypt(password_str.data(), password_str.length(),
+    error = (my_aes_encrypt(password_str.data(), password_str.size(),
                             encrypted_password, master_key.m_value.data(),
-                            master_key.m_value.length(), my_aes_256_cbc, iv,
+                            master_key.m_value.size(), my_aes_256_cbc, iv,
                             false) == MY_AES_BAD_DATA);
     m_encrypted_password =
-        Key_string(encrypted_password, sizeof(encrypted_password));
+        Key_string(encrypted_password, encrypted_password + sizeof(encrypted_password));
   }
 
   return error;
@@ -1264,7 +1264,7 @@ Key_string Rpl_encryption_header_v1::generate_new_file
   /* Generate password, it is a random string. */
   error = my_rand_buffer(password, sizeof(password));
   if (!error) {
-    password_str.append(password, sizeof(password));
+    password_str.insert(password_str.end(), password, password + sizeof(password));
   }
 
   if (error || encrypt_file_password(password_str) ||
