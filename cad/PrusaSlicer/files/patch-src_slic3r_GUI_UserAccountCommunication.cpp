--- src/slic3r/GUI/UserAccountCommunication.cpp.orig	2024-07-03 10:33:48 UTC
+++ src/slic3r/GUI/UserAccountCommunication.cpp
@@ -13,6 +13,7 @@
 #include <boost/filesystem.hpp>
 #include <boost/nowide/cstdio.hpp>
 #include <boost/nowide/fstream.hpp>
+#include <boost/nowide/convert.hpp>
 #include <curl/curl.h>
 #include <string>
 
@@ -37,7 +38,7 @@
 #include <CommonCrypto/CommonDigest.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <openssl/evp.h>
 #include <openssl/bio.h>
 #include <openssl/buffer.h>
@@ -137,7 +138,7 @@ bool load_secret(const std::string& opt, std::string& 
 #endif // wxUSE_SECRETSTORE 
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 void load_refresh_token_linux(std::string& refresh_token)
 {
         // Load refresh token from UserAccount.dat
@@ -201,7 +202,7 @@ UserAccountCommunication::UserAccountCommunication(wxE
         shared_session_key = key0;
 
     } else {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         load_refresh_token_linux(refresh_token);
 #endif
     }
@@ -253,7 +254,7 @@ void UserAccountCommunication::set_username(const std:
             save_secret("tokens", m_session->get_shared_session_key(), tokens);
         }
         else {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
             // If we can't store the tokens in secret store, store them in file with chmod 600
             boost::filesystem::path target(boost::filesystem::path(Slic3r::data_dir()) / "UserAccount.dat") ;
             std::string data = m_session->get_refresh_token();
