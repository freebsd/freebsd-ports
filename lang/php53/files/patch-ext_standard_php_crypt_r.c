--- ext/standard/php_crypt_r.c.orig	2011-08-22 09:54:16.000000000 +0200
+++ ext/standard/php_crypt_r.c	2011-08-22 09:54:49.000000000 +0200
@@ -382,7 +382,7 @@
 	/* Now make the output string */
 	memcpy(passwd, MD5_MAGIC, MD5_MAGIC_LEN);
 	strlcpy(passwd + MD5_MAGIC_LEN, sp, sl + 1);
-	strlcat(passwd, "$", 1);
+	strcat(passwd, "$");
 
 	PHP_MD5Final(final, &ctx);
 
