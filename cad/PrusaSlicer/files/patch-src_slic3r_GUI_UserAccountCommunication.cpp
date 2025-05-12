--- src/slic3r/GUI/UserAccountCommunication.cpp.orig	2025-04-15 11:04:24 UTC
+++ src/slic3r/GUI/UserAccountCommunication.cpp
@@ -38,7 +38,7 @@
 #include <CommonCrypto/CommonDigest.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <openssl/evp.h>
 #include <openssl/bio.h>
 #include <openssl/buffer.h>
@@ -140,7 +140,7 @@ bool load_secret(const std::string& opt, std::string& 
 #endif // wxUSE_SECRETSTORE 
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 void load_tokens_linux(UserAccountCommunication::StoreData& result)
 {
         // Load refresh token from UserAccount.dat
@@ -317,7 +317,7 @@ void UserAccountCommunication::set_username(const std:
                 BOOST_LOG_TRIVIAL(error) << "Failed to write tokens to the secret store.";
             }
         } else {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
             // If we can't store the tokens in secret store, store them in file with chmod 600
             boost::filesystem::path target(boost::filesystem::path(Slic3r::data_dir()) / "UserAccount.dat") ;
             std::string data = "||||";
@@ -640,7 +640,7 @@ void UserAccountCommunication::read_stored_data(UserAc
         }
         result.shared_session_key = key0;
     } else {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         load_tokens_linux(result);
 #endif
     }
