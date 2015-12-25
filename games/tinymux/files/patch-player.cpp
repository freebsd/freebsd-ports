--- player.cpp.orig	2015-12-25 12:25:58 UTC
+++ player.cpp
@@ -422,7 +422,7 @@ void ChangePassword(dbref player, const 
     s_Pass(player, pEncodedPassword);
 }
 
-#ifdef UNIX_DIGEST
+#if defined(UNIX_DIGEST) && !defined(OPENSSL_NO_SHA0)
 const UTF8 *p6h_xx_crypt(const UTF8 *szPassword)
 {
     // Calculate SHA-0 Hash.
