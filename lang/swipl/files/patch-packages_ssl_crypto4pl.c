--- packages/ssl/crypto4pl.c.orig	2026-01-22 19:39:26 UTC
+++ packages/ssl/crypto4pl.c
@@ -823,8 +823,60 @@ recover_ec(term_t t, ECKEY **rec)
 static int
 recover_ec(term_t t, ECKEY **rec)
 {
-  ECKEY *key;
+#ifdef USE_EVP_API
+  EVP_PKEY *key = NULL;
   BIGNUM *privkey = NULL;
+  unsigned char *codes;
+  size_t codes_len;
+  term_t tcurve, pubkey;
+  char *curve;
+  OSSL_PARAM_BLD *bld = NULL;
+  OSSL_PARAM *params = NULL;
+  EVP_PKEY_CTX *ctx = NULL;
+  int selection;
+  int rc = FALSE;
+
+  if ( !((tcurve = PL_new_term_ref()) &&
+	 (pubkey = PL_new_term_ref()) &&
+	 PL_get_arg(3, t, tcurve) &&
+	 PL_get_chars(tcurve, &curve, CVT_ATOM|CVT_STRING|CVT_EXCEPTION) &&
+	 PL_get_arg(2, t, pubkey) &&
+	 PL_get_nchars(pubkey, &codes_len, (char **) &codes,
+		       CVT_ATOM|CVT_STRING|CVT_LIST|CVT_EXCEPTION) &&
+	 get_bn_arg(1, t, &privkey)) )
+    return FALSE;
+
+  if ( !(bld = OSSL_PARAM_BLD_new()) ||
+       !OSSL_PARAM_BLD_push_utf8_string(bld, OSSL_PKEY_PARAM_GROUP_NAME,
+				       curve, 0) ||
+       !OSSL_PARAM_BLD_push_octet_string(bld, OSSL_PKEY_PARAM_PUB_KEY,
+					codes, codes_len) ||
+       (privkey && !OSSL_PARAM_BLD_push_BN(bld, OSSL_PKEY_PARAM_PRIV_KEY,
+					   privkey)) ||
+       !(params = OSSL_PARAM_BLD_to_param(bld)) ||
+       !(ctx = EVP_PKEY_CTX_new_from_name(NULL, "EC", NULL)) ||
+       EVP_PKEY_fromdata_init(ctx) <= 0 ||
+       EVP_PKEY_fromdata(ctx, &key,
+			 (selection = privkey ? EVP_PKEY_KEYPAIR
+					      : EVP_PKEY_PUBLIC_KEY),
+			 params) <= 0 )
+  { raise_ssl_error(ERR_get_error());
+    if ( key ) EVP_PKEY_free(key);
+    goto cleanup;
+  }
+
+  *rec = key;
+  rc = TRUE;
+
+cleanup:
+  if ( ctx ) EVP_PKEY_CTX_free(ctx);
+  if ( params ) OSSL_PARAM_free(params);
+  if ( bld ) OSSL_PARAM_BLD_free(bld);
+  BN_free(privkey);
+  return rc;
+#else
+  EC_KEY *key;
+  BIGNUM *privkey = NULL;
   term_t pubkey;
   unsigned char *codes;
   size_t codes_len;
@@ -832,55 +884,31 @@ recover_ec(term_t t, ECKEY **rec)
   char *curve;
 
   if ( !(tcurve &&
-         PL_get_arg(3, t, tcurve) &&
-         PL_get_chars(tcurve, &curve, CVT_ATOM|CVT_STRING|CVT_EXCEPTION) &&
-#ifdef USE_EVP_API
-         (key = EVP_EC_gen(curve))
-#else
-         (key = EC_KEY_new_by_curve_name(OBJ_sn2nid(curve)))
-#endif
-     ) )
+	 PL_get_arg(3, t, tcurve) &&
+	 PL_get_chars(tcurve, &curve, CVT_ATOM|CVT_STRING|CVT_EXCEPTION) &&
+	 (key = EC_KEY_new_by_curve_name(OBJ_sn2nid(curve)))) )
     return FALSE;
 
   if ( !get_bn_arg(1, t, &privkey) )
-  {
-#ifdef USE_EVP_API
-    EVP_PKEY_free(key);
-#else
-    EC_KEY_free(key);
-#endif
+  { EC_KEY_free(key);
     return FALSE;
   }
 
   if ( privkey )
-  {
-#ifdef USE_EVP_API
-    EVP_PKEY_set_bn_param(key, "priv", privkey);
-#else
     EC_KEY_set_private_key(key, privkey);
-#endif
-  }
 
   if ( (pubkey=PL_new_term_ref()) &&
        PL_get_arg(2, t, pubkey) &&
        PL_get_nchars(pubkey, &codes_len, (char **) &codes,
-                     CVT_ATOM|CVT_STRING|CVT_LIST|CVT_EXCEPTION) &&
-#ifdef USE_EVP_API
-        EVP_PKEY_set_octet_string_param(key, "pub", (const unsigned char*) codes, codes_len)
-#else
-       (key = o2i_ECPublicKey(&key, (const unsigned char**) &codes, codes_len))
-#endif
-  )
+		     CVT_ATOM|CVT_STRING|CVT_LIST|CVT_EXCEPTION) &&
+       (key = o2i_ECPublicKey(&key, (const unsigned char**) &codes, codes_len)) )
   { *rec = key;
     return TRUE;
   }
 
-#ifdef USE_EVP_API
-  EVP_PKEY_free(key);
-#else
   EC_KEY_free(key);
-#endif
   return FALSE;
+#endif
 }
 #endif
 
@@ -894,18 +922,6 @@ recover_rsa(term_t t, RSAKEY** keyp)
   RSAKEY *key = RSA_new();
 #endif
 
-#if SSL_API_0
-  if ( get_bn_arg(1, t, &key->n) &&
-       get_bn_arg(2, t, &key->e) &&
-       get_bn_arg(3, t, &key->d) &&
-       get_bn_arg(4, t, &key->p) &&
-       get_bn_arg(5, t, &key->q) &&
-       get_bn_arg(6, t, &key->dmp1) &&
-       get_bn_arg(7, t, &key->dmq1) &&
-       get_bn_arg(8, t, &key->iqmp)
-     )
-  {
-#else
   BIGNUM *n = NULL, *e = NULL, *d = NULL, *p = NULL,
     *q = NULL, *dmp1 = NULL, *dmq1 = NULL, *iqmp = NULL;
 
@@ -968,7 +984,6 @@ recover_rsa(term_t t, RSAKEY** keyp)
       return FALSE;
     }
 #endif
-#endif
     *keyp = key;
     return TRUE;
   }
@@ -1105,7 +1120,8 @@ pl_ecdsa_sign(term_t Private, term_t Data, term_t Enc,
   unsigned char *signature = NULL;
   int rc;
 #ifdef USE_EVP_API
-  size_t signature_len;
+  size_t signature_len = 0;
+  EVP_PKEY_CTX *sign_ctx;
 #else
   ECDSA_SIG *sig;
   unsigned int signature_len;
@@ -1116,15 +1132,20 @@ pl_ecdsa_sign(term_t Private, term_t Data, term_t Enc,
     return FALSE;
 
 #ifdef USE_EVP_API
-  signature_len = EVP_PKEY_get_size(key);
-  EVP_PKEY_CTX *sign_ctx = EVP_PKEY_CTX_new(key, NULL);
-  EVP_PKEY_sign_init(sign_ctx);
-  rc = EVP_PKEY_sign(sign_ctx,
-				 signature, &signature_len,
-				 data, (unsigned int)data_len);
-  EVP_PKEY_CTX_free(sign_ctx);
-  if (!rc)
+  if ( !(sign_ctx = EVP_PKEY_CTX_new(key, NULL)) ||
+       EVP_PKEY_sign_init(sign_ctx) <= 0 ||
+       EVP_PKEY_sign(sign_ctx, NULL, &signature_len,
+		     data, data_len) <= 0 ||
+       !(signature = OPENSSL_malloc(signature_len)) ||
+       EVP_PKEY_sign(sign_ctx, signature, &signature_len,
+		     data, data_len) <= 0 )
+  { if ( sign_ctx ) EVP_PKEY_CTX_free(sign_ctx);
+    EVP_PKEY_free(key);
+    OPENSSL_free(signature);
     return raise_ssl_error(ERR_get_error());
+  }
+  EVP_PKEY_CTX_free(sign_ctx);
+  EVP_PKEY_free(key);
 #else
   sig = ECDSA_do_sign(data, (unsigned int)data_len, key);
   EC_KEY_free(key);
@@ -1640,9 +1661,6 @@ pl_rsa_verify(term_t Public, term_t Type, term_t Enc,
 
 
 
-#ifndef HAVE_EVP_CIPHER_CTX_RESET
-#define EVP_CIPHER_CTX_reset(C) EVP_CIPHER_CTX_init(C)
-#endif
 
 static foreign_t
 pl_crypto_data_decrypt(term_t ciphertext_t, term_t algorithm_t,
@@ -2185,114 +2203,11 @@ - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 #include <pthread.h>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-static pthread_mutex_t *lock_cs;
-static long *lock_count;
-static void (*old_locking_callback)(int, int, const char*, int) = NULL;
-#ifdef HAVE_CRYPTO_THREADID_GET_CALLBACK
-static void (*old_id_callback)(CRYPTO_THREADID*) = NULL;
-#else
-static unsigned long (*old_id_callback)(void) = NULL;
-#endif
-
-static void
-crypto_thread_exit(void* ignored)
-{
-#ifdef HAVE_ERR_REMOVE_THREAD_STATE
-  ERR_remove_thread_state(0);
-#elif defined(HAVE_ERR_REMOVE_STATE)
-  ERR_remove_state(0);
-#else
-#error "Do not know how to remove SSL error state"
-#endif
-}
-
-static void
-pthreads_locking_callback(int mode, int type, const char *file, int line)
-{ if (mode & CRYPTO_LOCK)
-  { pthread_mutex_lock(&(lock_cs[type]));
-    lock_count[type]++;
-  } else
-  { pthread_mutex_unlock(&(lock_cs[type]));
-  }
-}
-
-
-/*  From OpenSSL manual:
-
-    id_function(void) is a function that returns a thread ID. It is not
-    needed on Windows nor on platforms where getpid() returns a different
-    ID for each thread (most notably Linux).
-
-    As for pthreads_win32 version 2, the thread identifier is no longer
-    integral, we are going to test this claim from the manual
-
-    JW: I don't think getpid() returns different thread ids on Linux any
-    longer, nor on many other Unix systems. Maybe we should use
-    PL_thread_self()?
-*/
-
-#ifndef __WINDOWS__
-#ifdef HAVE_CRYPTO_THREADID_SET_CALLBACK
-static void
-pthreads_thread_id(CRYPTO_THREADID* id)
-{ CRYPTO_THREADID_set_numeric(id, (unsigned long)pthread_self());
-}
-#else
-static unsigned long
-pthreads_thread_id(void)
-{ unsigned long ret;
-
-  ret=(unsigned long)pthread_self();
-  return(ret);
-}
-#endif /* OpenSSL 1.0.0 */
-#endif /* WINDOWS */
-#endif /* OpenSSL 1.1.0 */
-
-#if !defined(HAVE_CRYPTO_THREADID_GET_CALLBACK) && !defined(CRYPTO_THREADID_get_callback)
-#define CRYPTO_THREADID_get_callback CRYPTO_get_id_callback
-#define CRYPTO_THREADID_set_callback CRYPTO_set_id_callback
-#endif
-
 static int
 crypto_lib_init(void)
-{
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-  OpenSSL_add_all_algorithms();
-  ERR_load_crypto_strings();
-
-  if ( (old_id_callback=CRYPTO_THREADID_get_callback()) == 0 )
-  { int i;
-
-    lock_cs = OPENSSL_malloc(CRYPTO_num_locks() * sizeof(pthread_mutex_t));
-    lock_count = OPENSSL_malloc(CRYPTO_num_locks() * sizeof(long));
-
-    for (i=0; i<CRYPTO_num_locks(); i++)
-    { lock_count[i]=0;
-      pthread_mutex_init(&(lock_cs[i]), NULL);
-    }
-
-    old_locking_callback = CRYPTO_get_locking_callback();
-#ifndef __WINDOWS__			/* JW: why not for Windows? */
-    CRYPTO_THREADID_set_callback(pthreads_thread_id);
-#endif
-    CRYPTO_set_locking_callback(pthreads_locking_callback);
-
-    PL_thread_at_exit(crypto_thread_exit, NULL, TRUE);
-  }
-#endif /*OPENSSL_VERSION_NUMBER < 0x10100000L*/
-
-  return TRUE;
+{ return TRUE;
 }
 
-#else /*_REENTRANT*/
-
-static int
-crypto_lib_init(void)
-{ return FALSE;
-}
-
 #endif /*_REENTRANT*/
 
 
@@ -2302,18 +2217,6 @@ crypto_lib_exit(void)
  * One-time library exit calls
  */
 {
-/*
- * If the module is being unloaded, we should remove callbacks pointing to
- * our address space
- */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-#ifdef _REENTRANT
-#ifndef __WINDOWS__
-    CRYPTO_THREADID_set_callback(old_id_callback);
-#endif
-    CRYPTO_set_locking_callback(old_locking_callback);
-#endif
-#endif
     return 0;
 }
 
