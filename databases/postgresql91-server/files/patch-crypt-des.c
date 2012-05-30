--- ./contrib/pgcrypto/crypt-des.c
+++ ./contrib/pgcrypto/crypt-des.c
@@ -670,7 +670,8 @@ px_crypt_des(const char *key, const char *setting)
 	q = (uint8 *) keybuf;
 	while (q - (uint8 *) keybuf - 8)
 	{
-		if ((*q++ = *key << 1))
+		*q++ = *key << 1;
+		if (*key != '\0')
 			key++;
 	}
 	if (des_setkey((char *) keybuf))
