--- sql/stream_cipher.cc.orig	2023-11-24 10:33:10 UTC
+++ sql/stream_cipher.cc
@@ -45,7 +45,7 @@ bool Aes_ctr_cipher<TYPE>::open(const Key_string &pass
   m_header_size = header_size;
 #ifdef HAVE_BYTESTOKEY_SHA512_HANDLING
   if (EVP_BytesToKey(Aes_ctr::get_evp_cipher(), Aes_ctr::get_evp_md(), nullptr,
-                     password.data(), password.length(), 1, m_file_key,
+                     password.data(), password.size(), 1, m_file_key,
                      m_iv) == 0)
     return true;
 #else
