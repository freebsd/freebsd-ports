--- sql/stream_cipher.cc.orig	2024-07-12 19:15:25 UTC
+++ sql/stream_cipher.cc
@@ -46,7 +46,7 @@ bool Aes_ctr_cipher<TYPE>::open(const Key_string &pass
   m_header_size = header_size;
 #ifdef HAVE_BYTESTOKEY_SHA512_HANDLING
   if (EVP_BytesToKey(Aes_ctr::get_evp_cipher(), Aes_ctr::get_evp_md(), nullptr,
-                     password.data(), password.length(), 1, m_file_key,
+                     password.data(), password.size(), 1, m_file_key,
                      m_iv) == 0)
     return true;
 #else
