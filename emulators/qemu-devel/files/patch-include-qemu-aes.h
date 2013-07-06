--- a/include/qemu/aes.h
+++ b/include/qemu/aes.h
@@ -10,6 +10,15 @@ struct aes_key_st {
 };
 typedef struct aes_key_st AES_KEY;
 
+/* FreeBSD has it's own AES_set_decrypt_key in -lcrypto, avoid conflicts */
+#ifdef __FreeBSD__
+#define AES_set_encrypt_key QEMU_AES_set_encrypt_key
+#define AES_set_decrypt_key QEMU_AES_set_decrypt_key
+#define AES_encrypt QEMU_AES_encrypt
+#define AES_decrypt QEMU_AES_decrypt
+#define AES_cbc_encrypt QEMU_AES_cbc_encrypt
+#endif
+
 int AES_set_encrypt_key(const unsigned char *userKey, const int bits,
 	AES_KEY *key);
 int AES_set_decrypt_key(const unsigned char *userKey, const int bits,
