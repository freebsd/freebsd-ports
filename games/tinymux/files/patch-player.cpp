--- player.cpp.orig	2012-07-12 05:25:51 UTC
+++ player.cpp
@@ -422,7 +422,7 @@ void ChangePassword(dbref player, const
     s_Pass(player, pEncodedPassword);
 }
 
-#ifdef UNIX_DIGEST
+#if defined(UNIX_DIGEST) && !defined(OPENSSL_NO_SHA0)
 const UTF8 *p6h_xx_crypt(const UTF8 *szPassword)
 {
     // Calculate SHA-0 Hash.
@@ -598,7 +598,7 @@ const UTF8 *mux_crypt(const UTF8 *szPass
     case CRYPT_CLEARTEXT:
         return szPassword;
 
-#ifdef UNIX_DIGEST
+#if defined(UNIX_DIGEST) && !defined(OPENSSL_NO_SHA0)
     case CRYPT_P6H_XX:
         return p6h_xx_crypt(szPassword);
 #endif
