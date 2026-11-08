--- libdrizzle-1.0/libdrizzle/pack.h.orig	2026-11-06 18:08:06 UTC
+++ libdrizzle-1.0/libdrizzle/pack.h
@@ -87,6 +87,19 @@ uint8_t *drizzle_pack_auth(drizzle_con_st *con, uint8_
 uint8_t *drizzle_pack_auth(drizzle_con_st *con, uint8_t *ptr,
                            drizzle_return_t *ret_ptr);
 
+/**
+ * Build the authentication response for the negotiated auth plugin.
+ */
+DRIZZLE_API
+drizzle_return_t drizzle_auth_build(drizzle_con_st *con);
+
+/**
+ * Build the authentication response from the server's RSA public key.
+ */
+DRIZZLE_API
+drizzle_return_t drizzle_auth_build_rsa(drizzle_con_st *con, const char *pem,
+                                        size_t pem_size);
+
 /** @} */
 
 #ifdef __cplusplus
