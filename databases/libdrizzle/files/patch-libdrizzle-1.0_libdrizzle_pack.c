--- libdrizzle-1.0/libdrizzle/pack.c.orig	2026-11-06 18:08:06 UTC
+++ libdrizzle-1.0/libdrizzle/pack.c
@@ -41,6 +41,10 @@
 
 #include "common.h"
 
+#include <openssl/evp.h>
+#include <openssl/pem.h>
+#include <openssl/rsa.h>
+
 /*
  * Private declarations
  */
@@ -57,6 +61,21 @@ static drizzle_return_t _pack_scramble_hash(drizzle_co
 static drizzle_return_t _pack_scramble_hash(drizzle_con_st *con,
                                             uint8_t *buffer);
 
+/**
+ * Compute the caching_sha2_password fast path response.
+ */
+static drizzle_return_t _pack_sha2_scramble(drizzle_con_st *con);
+
+/**
+ * Put the password into the response as it is.
+ */
+static drizzle_return_t _pack_cleartext(drizzle_con_st *con);
+
+/**
+ * True if the password may travel without being encrypted.
+ */
+static int _auth_channel_is_safe(drizzle_con_st *con);
+
 /** @} */
 
 /*
@@ -207,56 +226,174 @@ uint8_t *drizzle_pack_auth(drizzle_con_st *con, uint8_
   ptr[0]= 0;
   ptr++;
 
-  if (con->options & DRIZZLE_CON_RAW_SCRAMBLE && con->scramble != NULL)
+  if (con->auth_response_size > 250)
   {
-    ptr[0]= DRIZZLE_MAX_SCRAMBLE_SIZE;
-    ptr++;
+    drizzle_set_error(con->drizzle, "drizzle_pack_auth",
+                      "auth response too large for the handshake:%zu",
+                      con->auth_response_size);
+    *ret_ptr= DRIZZLE_RETURN_INTERNAL_ERROR;
+    return ptr;
+  }
 
-    memcpy(ptr, con->scramble, DRIZZLE_MAX_SCRAMBLE_SIZE);
-    ptr+= DRIZZLE_MAX_SCRAMBLE_SIZE;
+  ptr[0]= (uint8_t)con->auth_response_size;
+  ptr++;
+
+  if (con->auth_response_size > 0)
+  {
+    memcpy(ptr, con->auth_response, con->auth_response_size);
+    ptr+= con->auth_response_size;
   }
-  else if (con->password[0] == 0)
+
+  if (con->db[0] != 0)
   {
-    ptr[0]= 0;
-    ptr++;
-    con->packet_size-= DRIZZLE_MAX_SCRAMBLE_SIZE;
+    memcpy(ptr, con->db, strlen(con->db));
+    ptr+= strlen(con->db);
   }
-  else
+
+  ptr[0]= 0;
+  ptr++;
+
+  *ret_ptr= DRIZZLE_RETURN_OK;
+  return ptr;
+}
+
+drizzle_return_t drizzle_auth_build(drizzle_con_st *con)
+{
+  drizzle_return_t ret;
+
+  con->auth_response_size= 0;
+
+  if (con->password[0] == 0)
+    return DRIZZLE_RETURN_OK;
+
+  /* The Drizzle protocol passes the password through as it is. */
+  if (!(con->options & DRIZZLE_CON_MYSQL))
   {
-    ptr[0]= DRIZZLE_MAX_SCRAMBLE_SIZE;
-    ptr++;
+    memset(con->auth_response, 0, DRIZZLE_MAX_SCRAMBLE_SIZE);
+    snprintf((char *)con->auth_response, DRIZZLE_MAX_SCRAMBLE_SIZE, "%s",
+             con->password);
+    con->auth_response_size= DRIZZLE_MAX_SCRAMBLE_SIZE;
+    return DRIZZLE_RETURN_OK;
+  }
 
-    if (con->options & DRIZZLE_CON_MYSQL && con->options & DRIZZLE_CON_AUTH_PLUGIN)
+  if (con->auth_plugin[0] == 0 ||
+      strcmp(con->auth_plugin, DRIZZLE_AUTH_PLUGIN_NATIVE) == 0)
+  {
+    ret= _pack_scramble_hash(con, con->auth_response);
+    if (ret != DRIZZLE_RETURN_OK)
+      return ret;
+
+    con->auth_response_size= DRIZZLE_MAX_SCRAMBLE_SIZE;
+    return DRIZZLE_RETURN_OK;
+  }
+
+  if (strcmp(con->auth_plugin, DRIZZLE_AUTH_PLUGIN_SHA2) == 0)
+    return _pack_sha2_scramble(con);
+
+  if (strcmp(con->auth_plugin, DRIZZLE_AUTH_PLUGIN_CLEAR) == 0)
+  {
+    if (!_auth_channel_is_safe(con))
     {
-      snprintf((char *)ptr, DRIZZLE_MAX_SCRAMBLE_SIZE, "%s", con->password);
-      ptr[DRIZZLE_MAX_SCRAMBLE_SIZE-1]= 0;
+      drizzle_set_error(con->drizzle, "drizzle_auth_build",
+                        "refusing to send the password in the clear over tcp");
+      return DRIZZLE_RETURN_AUTH_FAILED;
     }
-    else if (con->options & DRIZZLE_CON_MYSQL)
+
+    return _pack_cleartext(con);
+  }
+
+  if (strcmp(con->auth_plugin, DRIZZLE_AUTH_PLUGIN_SHA256) == 0)
+  {
+    if (_auth_channel_is_safe(con))
+      return _pack_cleartext(con);
+
+    if (con->options & DRIZZLE_CON_AUTH_NO_RSA)
     {
-      *ret_ptr= _pack_scramble_hash(con, ptr);
-      if (*ret_ptr != DRIZZLE_RETURN_OK)
-        return ptr;
+      drizzle_set_error(con->drizzle, "drizzle_auth_build",
+                        "%s needs the server public key", con->auth_plugin);
+      return DRIZZLE_RETURN_AUTH_FAILED;
     }
-    else // We assume Drizzle
-    {
-      snprintf((char *)ptr, DRIZZLE_MAX_SCRAMBLE_SIZE, "%s", con->password);
-      ptr[DRIZZLE_MAX_SCRAMBLE_SIZE-1]= 0;
-    }
 
-    ptr+= DRIZZLE_MAX_SCRAMBLE_SIZE;
+    /* Ask the server to send its RSA public key. */
+    con->auth_response[0]= 0x01;
+    con->auth_response_size= 1;
+    return DRIZZLE_RETURN_OK;
   }
 
-  if (con->db[0] != 0)
+  drizzle_set_error(con->drizzle, "drizzle_auth_build",
+                    "unsupported authentication plugin:%s", con->auth_plugin);
+  return DRIZZLE_RETURN_AUTH_FAILED;
+}
+
+drizzle_return_t drizzle_auth_build_rsa(drizzle_con_st *con, const char *pem,
+                                        size_t pem_size)
+{
+  uint8_t plain[DRIZZLE_MAX_PASSWORD_SIZE + 1];
+  size_t size= strlen(con->password) + 1;
+  size_t out_size= DRIZZLE_MAX_AUTH_RESPONSE_SIZE;
+  BIO *bio;
+  EVP_PKEY *key;
+  EVP_PKEY_CTX *ctx;
+  uint32_t x;
+
+  if (con->scramble == NULL)
   {
-    memcpy(ptr, con->db, strlen(con->db));
-    ptr+= strlen(con->db);
+    drizzle_set_error(con->drizzle, "drizzle_auth_build_rsa",
+                      "no scramble buffer");
+    return DRIZZLE_RETURN_NO_SCRAMBLE;
   }
 
-  ptr[0]= 0;
-  ptr++;
+  if (size > sizeof(plain))
+  {
+    drizzle_set_error(con->drizzle, "drizzle_auth_build_rsa",
+                      "password too long:%zu", size);
+    return DRIZZLE_RETURN_INTERNAL_ERROR;
+  }
 
-  *ret_ptr= DRIZZLE_RETURN_OK;
-  return ptr;
+  /* The password, trailing NULL included, is XORed with the scramble. */
+  for (x= 0; x < size; x++)
+  {
+    plain[x]= (uint8_t)con->password[x] ^
+              con->scramble[x % DRIZZLE_MAX_SCRAMBLE_SIZE];
+  }
+
+  bio= BIO_new_mem_buf(pem, (int)pem_size);
+  if (bio == NULL)
+    return DRIZZLE_RETURN_MEMORY;
+
+  key= PEM_read_bio_PUBKEY(bio, NULL, NULL, NULL);
+  BIO_free(bio);
+
+  if (key == NULL)
+  {
+    drizzle_set_error(con->drizzle, "drizzle_auth_build_rsa",
+                      "could not read the server public key");
+    return DRIZZLE_RETURN_AUTH_FAILED;
+  }
+
+  ctx= EVP_PKEY_CTX_new(key, NULL);
+  if (ctx == NULL)
+  {
+    EVP_PKEY_free(key);
+    return DRIZZLE_RETURN_MEMORY;
+  }
+
+  if (EVP_PKEY_encrypt_init(ctx) != 1 ||
+      EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING) != 1 ||
+      EVP_PKEY_encrypt(ctx, con->auth_response, &out_size, plain, size) != 1)
+  {
+    EVP_PKEY_CTX_free(ctx);
+    EVP_PKEY_free(key);
+    drizzle_set_error(con->drizzle, "drizzle_auth_build_rsa",
+                      "could not encrypt the password");
+    return DRIZZLE_RETURN_AUTH_FAILED;
+  }
+
+  EVP_PKEY_CTX_free(ctx);
+  EVP_PKEY_free(key);
+
+  con->auth_response_size= out_size;
+  return DRIZZLE_RETURN_OK;
 }
 
 /*
@@ -308,4 +445,71 @@ static drizzle_return_t _pack_scramble_hash(drizzle_co
     buffer[x]= buffer[x] ^ hash_tmp1[x];
 
   return DRIZZLE_RETURN_OK;
+}
+
+static drizzle_return_t _pack_sha2_scramble(drizzle_con_st *con)
+{
+  uint8_t hash_tmp1[32];
+  uint8_t hash_tmp2[32];
+  uint8_t hash_tmp3[32];
+  uint8_t buffer[32 + DRIZZLE_MAX_SCRAMBLE_SIZE];
+  unsigned int size;
+  uint32_t x;
+
+  if (con->scramble == NULL)
+  {
+    drizzle_set_error(con->drizzle, "_pack_sha2_scramble",
+                      "no scramble buffer");
+    return DRIZZLE_RETURN_NO_SCRAMBLE;
+  }
+
+  /* XOR(SHA256(password),
+         SHA256(SHA256(SHA256(password)), scramble)) */
+  if (EVP_Digest(con->password, strlen(con->password), hash_tmp1, &size,
+                 EVP_sha256(), NULL) != 1 ||
+      EVP_Digest(hash_tmp1, sizeof(hash_tmp1), hash_tmp2, &size,
+                 EVP_sha256(), NULL) != 1)
+  {
+    drizzle_set_error(con->drizzle, "_pack_sha2_scramble", "SHA256 failed");
+    return DRIZZLE_RETURN_INTERNAL_ERROR;
+  }
+
+  memcpy(buffer, hash_tmp2, sizeof(hash_tmp2));
+  memcpy(buffer + sizeof(hash_tmp2), con->scramble, DRIZZLE_MAX_SCRAMBLE_SIZE);
+
+  if (EVP_Digest(buffer, sizeof(buffer), hash_tmp3, &size, EVP_sha256(),
+                 NULL) != 1)
+  {
+    drizzle_set_error(con->drizzle, "_pack_sha2_scramble", "SHA256 failed");
+    return DRIZZLE_RETURN_INTERNAL_ERROR;
+  }
+
+  for (x= 0; x < sizeof(hash_tmp1); x++)
+    con->auth_response[x]= hash_tmp1[x] ^ hash_tmp3[x];
+
+  con->auth_response_size= sizeof(hash_tmp1);
+
+  return DRIZZLE_RETURN_OK;
+}
+
+static drizzle_return_t _pack_cleartext(drizzle_con_st *con)
+{
+  size_t size= strlen(con->password) + 1;
+
+  if (size > DRIZZLE_MAX_AUTH_RESPONSE_SIZE)
+  {
+    drizzle_set_error(con->drizzle, "_pack_cleartext", "password too long:%zu",
+                      size);
+    return DRIZZLE_RETURN_INTERNAL_ERROR;
+  }
+
+  memcpy(con->auth_response, con->password, size);
+  con->auth_response_size= size;
+
+  return DRIZZLE_RETURN_OK;
+}
+
+static int _auth_channel_is_safe(drizzle_con_st *con)
+{
+  return (con->socket_type == DRIZZLE_CON_SOCKET_UDS);
 }
