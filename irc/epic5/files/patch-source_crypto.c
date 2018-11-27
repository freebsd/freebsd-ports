--- source/crypto.c.orig	2016-08-05 20:49:07 UTC
+++ source/crypto.c
@@ -282,28 +282,33 @@ static char *	decipher_evp (const unsigned char *passw
 	unsigned char	*iv = NULL;
 	unsigned long errcode;
 	int	outlen2;
-        EVP_CIPHER_CTX a;
-        EVP_CIPHER_CTX_init(&a);
-	EVP_CIPHER_CTX_set_padding(&a, 0);
+        EVP_CIPHER_CTX *context = EVP_CIPHER_CTX_new();
 
+	if(context == NULL) {
+		yell("ERROR: Could not generate cipher context");
+		return NULL;
+	}
+
+	EVP_CIPHER_CTX_set_padding(context, 0);
+
 	if (ivsize > 0)
 		iv = new_malloc(ivsize);
 	outbuf = new_malloc(cipherlen + 1024);
 	if (ivsize > 0)
 		memcpy(iv, ciphertext, ivsize);
 
-        EVP_DecryptInit_ex(&a, type, NULL, NULL, iv);
-	EVP_CIPHER_CTX_set_key_length(&a, passwdlen);
-	EVP_CIPHER_CTX_set_padding(&a, 0);
-        EVP_DecryptInit_ex(&a, NULL, NULL, passwd, NULL);
+        EVP_DecryptInit_ex(context, type, NULL, NULL, iv);
+	EVP_CIPHER_CTX_set_key_length(context, passwdlen);
+	EVP_CIPHER_CTX_set_padding(context, 0);
+        EVP_DecryptInit_ex(context, NULL, NULL, passwd, NULL);
 
-        if (EVP_DecryptUpdate(&a, outbuf, outlen, ciphertext, cipherlen) != 1)
+        if (EVP_DecryptUpdate(context, outbuf, outlen, ciphertext, cipherlen) != 1)
 		yell("EVP_DecryptUpdate died.");
-	if (EVP_DecryptFinal_ex(&a, outbuf + (*outlen), &outlen2) != 1)
+	if (EVP_DecryptFinal_ex(context, outbuf + (*outlen), &outlen2) != 1)
 		yell("EVP_DecryptFinal_Ex died.");
 	*outlen += outlen2;
 
-        EVP_CIPHER_CTX_cleanup(&a);
+        EVP_CIPHER_CTX_free(context);
 
 	ERR_load_crypto_strings();
 	while ((errcode = ERR_get_error()))
@@ -454,10 +459,15 @@ static char *	cipher_evp (const unsigned char *passwd,
 	unsigned long errcode;
 	u_32int_t	randomval;
 	int		iv_count;
-        EVP_CIPHER_CTX a;
-        EVP_CIPHER_CTX_init(&a);
-	EVP_CIPHER_CTX_set_padding(&a, 0);
+        EVP_CIPHER_CTX *context = EVP_CIPHER_CTX_new();
 
+	if(context == NULL) {
+		yell("ERROR: Could not generate cipher context");
+		return NULL;
+	}
+
+	EVP_CIPHER_CTX_set_padding(context, 0);
+
 	if (ivsize < 0)
 		ivsize = 0;		/* Shenanigans! */
 
@@ -480,12 +490,12 @@ static char *	cipher_evp (const unsigned char *passwd,
 	if (iv)
 		memcpy(outbuf, iv, ivsize);
 
-        EVP_EncryptInit_ex(&a, type, NULL, NULL, iv);
-	EVP_CIPHER_CTX_set_key_length(&a, passwdlen);
-        EVP_EncryptInit_ex(&a, NULL, NULL, passwd, NULL);
-        EVP_EncryptUpdate(&a, outbuf + ivsize, &outlen, plaintext, plaintextlen);
-	EVP_EncryptFinal_ex(&a, outbuf + ivsize + outlen, &extralen);
-        EVP_CIPHER_CTX_cleanup(&a);
+        EVP_EncryptInit_ex(context, type, NULL, NULL, iv);
+	EVP_CIPHER_CTX_set_key_length(context, passwdlen);
+        EVP_EncryptInit_ex(context, NULL, NULL, passwd, NULL);
+        EVP_EncryptUpdate(context, outbuf + ivsize, &outlen, plaintext, plaintextlen);
+	EVP_EncryptFinal_ex(context, outbuf + ivsize + outlen, &extralen);
+        EVP_CIPHER_CTX_free(context);
 	outlen += extralen;
 
 	ERR_load_crypto_strings();
