--- packages/ssl/ssl4pl.c.orig	2026-01-22 19:39:26 UTC
+++ packages/ssl/ssl4pl.c
@@ -74,6 +74,12 @@
 
 #define SSL_MAX_CERT_KEY_PAIRS 12
 
+#if !HAVE_ASN1_STRING_get0_data
+#define ASN1_STRING_get0_data(x) (x)->data
+#define ASN1_STRING_length(x)    (x)->length
+#define ASN1_STRING_type(x)      (x)->type
+#endif
+
 typedef int BOOL;
 #ifndef TRUE
 #define TRUE 1
@@ -458,12 +464,12 @@ unify_asn1_time(term_t term, const ASN1_TIME *time)
 { time_t result = 0;
   char buffer[24];
   char* pbuffer = buffer;
-  size_t length = time->length;
-  char * source = (char *)time->data;
+  size_t length = ASN1_STRING_length(time);
+  const char * source = (const char *)ASN1_STRING_get0_data(time);
   struct tm time_tm;
   time_t lSecondsFromUTC;
 
-  if (time->type == V_ASN1_UTCTIME)
+  if (ASN1_STRING_type(time) == V_ASN1_UTCTIME)
   {  if ((length < 11) || (length > 17))
      {  ssl_deb(2, "Unable to parse time - expected either 11 or 17 chars,"
 		   " not %d", length);
@@ -581,8 +587,6 @@ algorithm_to_type(const ASN1_OBJECT* algorithm, int *n
   return EVP_get_digestbynid(*nid);
 }
 
-#if defined(HAVE_X509_DIGEST) && defined(HAVE_X509_CRL_DIGEST)
-
 static int
 hash_X509_digest_wrapper(const void *data, const EVP_MD *type,
 			 unsigned char* md, unsigned int *l)
@@ -616,70 +620,9 @@ unify_hash(term_t hash, const ASN1_OBJECT* algorithm,
   return unify_bytes_hex(hash, digest_length, digest);
 }
 
-#else
 
 static int
-i2d_X509_CRL_INFO_wrapper(void* i, unsigned char** d)
-{ return i2d_X509_CRL_INFO(i, d);
-}
-
-static int
-i2d_X509_CINF_wrapper(void* i, unsigned char** d)
-{ return i2d_X509_CINF(i, d);
-}
-
-
-static int
-unify_hash(term_t hash, const ASN1_OBJECT* algorithm,
-	   int (*i2d)(void*, unsigned char**), void * data)
-{ int nid;
-  const EVP_MD *type = algorithm_to_type(algorithm, &nid);
-  EVP_MD_CTX *ctx = EVP_MD_CTX_new();
-  int digestible_length;
-  unsigned char* digest_buffer;
-  unsigned char digest[EVP_MAX_MD_SIZE];
-  unsigned int digest_length;
-  unsigned char* p;
-  /* Generate hash */
-
-  if ( type == NULL )
-    return PL_unify_term(hash,
-                         PL_FUNCTOR, FUNCTOR_unsupported_hash_algorithm1,
-                         PL_INT, nid);
-
-  digestible_length=i2d(data,NULL);
-  digest_buffer = PL_malloc(digestible_length);
-  if ( digest_buffer == NULL )
-    return PL_resource_error("memory");
-
-  /* i2d_X509_CINF will change the value of p. We need to pass in a copy */
-  p = digest_buffer;
-  i2d(data,&p);
-  if (!EVP_DigestInit(ctx, type))
-  { EVP_MD_CTX_free(ctx);
-    PL_free(digest_buffer);
-    return raise_ssl_error(ERR_get_error());
-  }
-  if (!EVP_DigestUpdate(ctx, digest_buffer, digestible_length))
-  { EVP_MD_CTX_free(ctx);
-    PL_free(digest_buffer);
-    return raise_ssl_error(ERR_get_error());
-  }
-  if (!EVP_DigestFinal(ctx, digest, &digest_length))
-  { EVP_MD_CTX_free(ctx);
-    PL_free(digest_buffer);
-    return raise_ssl_error(ERR_get_error());
-  }
-  EVP_MD_CTX_free(ctx);
-  PL_free(digest_buffer);
-  return unify_bytes_hex(hash, digest_length, digest);
-}
-
-#endif
-
-
-static int
-unify_name(term_t term, X509_NAME* name)
+unify_name(term_t term, const X509_NAME* name)
 { int ni;
   term_t list = PL_copy_term_ref(term);
   term_t item = PL_new_term_ref();
@@ -688,8 +631,8 @@ unify_name(term_t term, X509_NAME* name)
     return PL_unify_term(term, PL_CHARS, "<null>");
 
   for (ni = 0; ni < X509_NAME_entry_count(name); ni++)
-  { X509_NAME_ENTRY* e = X509_NAME_get_entry(name, ni);
-    ASN1_STRING* entry_data = X509_NAME_ENTRY_get_data(e);
+  { const X509_NAME_ENTRY* e = X509_NAME_get_entry(name, ni);
+    const ASN1_STRING* entry_data = X509_NAME_ENTRY_get_data(e);
     unsigned char *utf8_data;
     int rc;
 
@@ -711,37 +654,7 @@ unify_name(term_t term, X509_NAME* name)
   return PL_unify_nil(list);
 }
 
-#if SSL_API_0
-#define X509_REVOKED_get0_serialNumber(R) ((R)->serialNumber)
-#define X509_REVOKED_get0_revocationDate(R) ((R)->revocationDate)
-#define EVP_PKEY_base_id(key) ((key)->type)
-#define X509_CRL_get0_nextUpdate(C) X509_CRL_get_nextUpdate(C)
-#ifndef HAVE_X509_CRL_GET0_SIGNATURE
-/* Avoid conflict if the prototype is there, but the function is not */
-#define X509_CRL_get0_signature my_X509_CRL_get0_signature
 
-static void
-X509_CRL_get0_signature(const X509_CRL *crl, const ASN1_BIT_STRING **psig,
-			const X509_ALGOR **palg)
-{ *psig = crl->signature;
-  *palg = crl->sig_alg;
-}
-#endif
-
-#ifndef HAVE_X509_GET0_SIGNATURE
-/* Avoid conflict if the prototype is there, but the function is not */
-#define X509_get0_signature my_X509_get0_signature
-
-static void
-X509_get0_signature(const ASN1_BIT_STRING **psig, const X509_ALGOR **palg,
-		    const X509 *data)
-{
-  *psig = data->signature;
-  *palg = data->sig_alg;
-}
-#endif
-#endif
-
 static int
 unify_crl(term_t term, X509_CRL* crl)
 { const ASN1_BIT_STRING *psig;
@@ -769,13 +682,9 @@ unify_crl(term_t term, X509_CRL* crl)
   X509_CRL_get0_signature(crl, &psig, &palg);
   i2a_ASN1_INTEGER(mem, (ASN1_BIT_STRING *) psig);
   if (!(unify_name(issuer, X509_CRL_get_issuer(crl)) &&
-#ifdef HAVE_X509_CRL_DIGEST
 	unify_hash(hash, palg->algorithm, hash_X509_crl_digest_wrapper, crl) &&
-#else
-        unify_hash(hash, palg->algorithm, i2d_X509_CRL_INFO_wrapper, crl->crl) &&
-#endif
         unify_asn1_time(next_update, X509_CRL_get0_nextUpdate(crl)) &&
-        unify_bytes_hex(signature, psig->length, psig->data) &&
+        unify_bytes_hex(signature, ASN1_STRING_length(psig), ASN1_STRING_get0_data(psig)) &&
         PL_unify_term(term,
                       PL_LIST, 5,
                       PL_FUNCTOR, FUNCTOR_issuername1,
@@ -819,18 +728,6 @@ unify_rsa(term_t item, RSAKEY* rsa)
 static int
 unify_rsa(term_t item, RSAKEY* rsa)
 {
-#if SSL_API_0
-  return ( PL_unify_functor(item, FUNCTOR_rsa8) &&
-	   unify_bignum_arg(1, item, rsa->n) &&
-	   unify_bignum_arg(2, item, rsa->e) &&
-	   unify_bignum_arg(3, item, rsa->d) &&
-	   unify_bignum_arg(4, item, rsa->p) &&
-	   unify_bignum_arg(5, item, rsa->q) &&
-	   unify_bignum_arg(6, item, rsa->dmp1) &&
-	   unify_bignum_arg(7, item, rsa->dmq1) &&
-	   unify_bignum_arg(8, item, rsa->iqmp)
-	 );
-#else
 #ifdef USE_EVP_API
   BIGNUM *n = NULL, *e = NULL, *d = NULL,
     *p = NULL, *q = NULL,
@@ -861,7 +758,6 @@ unify_rsa(term_t item, RSAKEY* rsa)
 	   unify_bignum_arg(7, item, dmq1) &&
 	   unify_bignum_arg(8, item, iqmp)
 	 );
-#endif
 }
 
 #ifndef OPENSSL_NO_EC
@@ -871,25 +767,31 @@ unify_ec(term_t item, ECKEY *key)
   int rc;
   term_t privkey, pubkey;
 #ifdef USE_EVP_API
-  BIGNUM* priv_bn;
-  size_t publen;
-  size_t grouplen;
-  unsigned char* group;
-  EVP_PKEY_get_octet_string_param(key, "pub", NULL, 0, &publen);
+  BIGNUM* priv_bn = NULL;
+  size_t publen = 0;
+  char group[80];
+  if ( !EVP_PKEY_get_octet_string_param(key, OSSL_PKEY_PARAM_PUB_KEY,
+					NULL, 0, &publen) )
+    return raise_ssl_error(ERR_get_error());
   buf = OPENSSL_malloc(publen);
-  EVP_PKEY_get_octet_string_param(key, "pub", buf, publen, NULL);
-  EVP_PKEY_get_bn_param(key, "priv", &priv_bn);
-  EVP_PKEY_get_octet_string_param(key, "group", NULL, 0, &grouplen);
-  group = PL_malloc(grouplen);
-  EVP_PKEY_get_octet_string_param(key, "group", group, grouplen, NULL);
-
+  if ( !buf )
+    return raise_ssl_error(ERR_get_error());
+  if ( !EVP_PKEY_get_octet_string_param(key, OSSL_PKEY_PARAM_PUB_KEY,
+					buf, publen, NULL) ||
+       !EVP_PKEY_get_utf8_string_param(key, OSSL_PKEY_PARAM_GROUP_NAME,
+				       group, sizeof(group), NULL) )
+  { OPENSSL_free(buf);
+    return raise_ssl_error(ERR_get_error());
+  }
+  /* "priv" is absent for public-only keys; ignore failure here. */
+  EVP_PKEY_get_bn_param(key, OSSL_PKEY_PARAM_PRIV_KEY, &priv_bn);
 #else
   int publen = i2o_ECPublicKey(key, &buf);
   const BIGNUM* priv_bn = EC_KEY_get0_private_key(key);
   const char* group = OBJ_nid2sn(EC_GROUP_get_curve_name(EC_KEY_get0_group(key)));
-#endif
   if ( publen < 0 )
     return raise_ssl_error(ERR_get_error());
+#endif
 
   rc = ( (pubkey = PL_new_term_ref()) &&
          (privkey = PL_new_term_ref()) &&
@@ -903,7 +805,7 @@ unify_ec(term_t item, ECKEY *key)
 
   OPENSSL_free(buf);
 #ifdef USE_EVP_API
-  PL_free(group);
+  BN_free(priv_bn);
 #endif
   return rc;
 }
@@ -995,18 +897,8 @@ unify_private_key(EVP_PKEY* key, term_t item)
 { return unify_key(key, FUNCTOR_private_key1, item);
 }
 
-#ifndef HAVE_X509_GET0_NOTBEFORE
-#define X509_get0_notBefore(C) X509_get_notBefore(C)
-#endif
-#ifndef HAVE_X509_GET0_NOTAFTER
-#define X509_get0_notAfter(C) X509_get_notAfter(C)
-#endif
 
-#ifndef GET0SIG_CONST_T
-#define GET0SIG_CONST_T
-#endif
 
-
 static int
 release_cert(atom_t atom)
 { X509 *cert = PL_blob_data(atom, NULL, NULL);
@@ -1325,7 +1217,7 @@ fetch_crls(term_t Field, X509* cert)
 static foreign_t
 fetch_crls(term_t Field, X509* cert)
 { unsigned int crl_ext_id;
-  X509_EXTENSION * crl_ext = NULL;
+  const X509_EXTENSION * crl_ext = NULL;
 
   crl_ext_id = X509_get_ext_by_NID(cert, NID_crl_distribution_points, -1);
   crl_ext = X509_get_ext(cert, crl_ext_id);
@@ -1352,7 +1244,7 @@ fetch_crls(term_t Field, X509* cert)
         { name = sk_GENERAL_NAME_value(point->distpoint->name.fullname, j);
           if (name != NULL && name->type == GEN_URI)
           { if (!(PL_unify_list(crl_list, crl_item, crl_list) &&
-                  PL_unify_atom_chars(crl_item, (const char *)name->d.ia5->data)))
+                  PL_unify_atom_chars(crl_item, (const char *)ASN1_STRING_get0_data(name->d.ia5))))
             {
               CRL_DIST_POINTS_free(distpoints);
               return FALSE;
@@ -1370,16 +1262,11 @@ fetch_crls(term_t Field, X509* cert)
   }
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-#define ASN1_STRING_get0_data(D) ASN1_STRING_data(D)
-#define X509_STORE_CTX_get0_cert(C) ((C)->cert)
-#endif
 
-
 static foreign_t
 fetch_sans(term_t Field, X509* cert)
 { unsigned int san_ext_id;
-  X509_EXTENSION * san_ext = NULL;
+  const X509_EXTENSION * san_ext = NULL;
 
   san_ext_id = X509_get_ext_by_NID(cert, NID_subject_alt_name, -1);
   san_ext = X509_get_ext(cert, san_ext_id);
@@ -1415,17 +1302,17 @@ fetch_signature(term_t Field, X509* cert)
 
 static foreign_t
 fetch_signature(term_t Field, X509* cert)
-{ GET0SIG_CONST_T ASN1_BIT_STRING *psig;
-  GET0SIG_CONST_T X509_ALGOR *palg;
+{ const ASN1_BIT_STRING *psig;
+  const X509_ALGOR *palg;
   X509_get0_signature(&psig, &palg, cert);
-  return unify_bytes_hex(Field, psig->length, psig->data);
+  return unify_bytes_hex(Field, ASN1_STRING_length(psig), ASN1_STRING_get0_data(psig));
 }
 
 
 static foreign_t
 fetch_signature_algorithm(term_t Field, X509* cert)
-{ GET0SIG_CONST_T ASN1_BIT_STRING *psig;
-  GET0SIG_CONST_T X509_ALGOR *palg;
+{ const ASN1_BIT_STRING *psig;
+  const X509_ALGOR *palg;
   const char *salgorithm;
 
   X509_get0_signature(&psig, &palg, cert);
@@ -1437,15 +1324,11 @@ fetch_hash(term_t Field, X509* cert)
 
 static foreign_t
 fetch_hash(term_t Field, X509* cert)
-{ GET0SIG_CONST_T ASN1_BIT_STRING *psig;
-  GET0SIG_CONST_T X509_ALGOR *palg;
+{ const ASN1_BIT_STRING *psig;
+  const X509_ALGOR *palg;
 
   X509_get0_signature(&psig, &palg, cert);
-#ifdef HAVE_X509_DIGEST
   return unify_hash(Field, palg->algorithm, hash_X509_digest_wrapper, cert);
-#else
-  return unify_hash(Field, palg->algorithm, i2d_X509_CINF_wrapper, cert->cert_info);
-#endif
 }
 
 
@@ -1767,9 +1650,6 @@ pl_sni_hook(PL_SSL *config, const char *host)
   return new_config;
 }
 
-#ifndef HAVE_X509_STORE_CTX_GET0_CHAIN
-#define X509_STORE_CTX_get0_chain(c) X509_STORE_CTX_get_chain(c)
-#endif
 
 static BOOL
 pl_cert_verify_hook(PL_SSL *config,
@@ -2784,12 +2664,6 @@ get_dh2048(void)
         if (dh == NULL) return NULL;
 #endif
 
-#if SSL_API_0
-        dh->p=BN_bin2bn(dhp_2048,sizeof(dhp_2048),NULL);
-        dh->g=BN_bin2bn(dhg_2048,sizeof(dhg_2048),NULL);
-        if ((dh->p == NULL) || (dh->g == NULL))
-          { DH_free(dh); return(NULL); }
-#else
         BIGNUM *dhp_bn, *dhg_bn;
 
         dhp_bn = BN_bin2bn(dhp_2048, sizeof (dhp_2048), NULL);
@@ -2808,7 +2682,6 @@ get_dh2048(void)
           BN_free(dhg_bn);
           return NULL;
         }
-#endif
         return dh;
         }
 
@@ -2940,8 +2813,6 @@ ssl_init_min_max_protocol(PL_SSL *config)
 }
 
 
-#ifdef HAVE_SSL_CTX_SET_ALPN_PROTOS
-
 static int
 ssl_server_alpn_select_cb(SSL *ssl,
 			  const unsigned char **out, unsigned char *outlen,
@@ -3049,17 +2920,12 @@ ssl_init_alpn_protos(PL_SSL *config)
   }
 }
 
-#endif /*HAVE_SSL_CTX_SET_ALPN_PROTOS*/
-
 static int
 set_malleable_options(PL_SSL *config)
 {
 
 #ifndef OPENSSL_NO_EC
   ECKEY *ecdh;
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-  char *curve = "prime256v1";
-#else
   /* In OpenSSL >= 1.1.0, ECDH support is always enabled.  Therefore,
    * if ecdh_curve/1 is not specified, we use the existing defaults.
    *
@@ -3069,7 +2935,6 @@ set_malleable_options(PL_SSL *config)
    * We should provide a binding for the more general function.
    */
   char *curve = NULL;
-#endif
 
   if (config->ecdh_curve)
     curve = config->ecdh_curve;
@@ -3106,9 +2971,7 @@ set_malleable_options(PL_SSL *config)
 
   ssl_init_sni(config);
   ssl_init_min_max_protocol(config);
-#ifdef HAVE_SSL_CTX_SET_ALPN_PROTOS
   ssl_init_alpn_protos(config);
-#endif
 
   return TRUE;
 }
@@ -3164,11 +3027,6 @@ ssl_lib_init(void)
  * One-time library initialization code
  */
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-    (void) SSL_library_init();
-    SSL_load_error_strings();
-#endif
-
     if ((ctx_idx = SSL_CTX_get_ex_new_index( 0
                                        , NULL
                                        , ssl_config_new
@@ -3241,7 +3099,6 @@ ssl_ssl_bio(PL_SSL *config, IOSTREAM* sread, IOSTREAM*
       SSL_set_tlsext_host_name(instance->ssl, config->host);
 #endif
 #ifdef HAVE_X509_CHECK_HOST
-#if (defined(HAVE_X509_VERIFY_PARAM_ID) || OPENSSL_VERSION_NUMBER >= 0x10100000L)
     X509_VERIFY_PARAM *param = SSL_get0_param(instance->ssl);
     /* This could in theory be user-configurable. The documentation at
        https://wiki.openssl.org/index.php/Manual:X509_check_host(3)
@@ -3253,7 +3110,6 @@ ssl_ssl_bio(PL_SSL *config, IOSTREAM* sread, IOSTREAM*
     X509_VERIFY_PARAM_set_hostflags(param, 0);
     X509_VERIFY_PARAM_set1_host(param, config->host, 0);
 #endif
-#endif
   }
 
   SSL_set_session_id_context(instance->ssl, (unsigned char*)"SWI-Prolog", 10);
@@ -3615,50 +3471,8 @@ get_ssl_method(term_t method)
 
 static const SSL_METHOD *
 get_ssl_method(term_t method)
-{ const SSL_METHOD *ssl_method = NULL;
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-  atom_t method_name;
-#endif
-
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-  if ( !method )
-  { method_name = ATOM_sslv23;
-  } else if ( !PL_get_atom(method, &method_name) )
-  { PL_domain_error("ssl_method", method);
-    return NULL;
-  }
-
-  if ( method_name == ATOM_sslv23 )
-    ssl_method = SSLv23_method();
-#ifndef OPENSSL_NO_SSL2
-  else if ( method_name == ATOM_sslv2 )
-    ssl_method = SSLv2_method();
-#endif
-#ifndef OPENSSL_NO_SSL3_METHOD
-  else if ( method_name == ATOM_sslv3 )
-    ssl_method = SSLv3_method();
-#endif
-#ifdef SSL_OP_NO_TLSv1
-  else if ( method_name == ATOM_tlsv1 )
-    ssl_method = TLSv1_method();
-#endif
-#ifdef SSL_OP_NO_TLSv1_1
-  else if ( method_name == ATOM_tlsv1_1 )
-    ssl_method = TLSv1_1_method();
-#endif
-#ifdef SSL_OP_NO_TLSv1_2
-  else if ( method_name == ATOM_tlsv1_2 )
-    ssl_method = TLSv1_2_method();
-#endif
-  else
-  { PL_domain_error("ssl_method", method);
-    return NULL;
-  }
-#else
-  ssl_method = TLS_method();  /* In OpenSSL >= 1.1.0, always use TLS_method() */
-#endif
-
-  return ssl_method;
+{ (void)method;
+  return TLS_method();
 }
 
 
@@ -4368,24 +4182,12 @@ pl_ssl_session(term_t stream_t, term_t session_t)
        !(session = SSL_get1_session(ssl)) )
     return PL_existence_error("ssl_session", stream_t);
 
-#ifndef HAVE_SSL_SESSION_GET_PROTOCOL_VERSION
-  version = session->ssl_version;
-  master_key = session->master_key;
-  master_key_length = session->master_key_length;
-  /* session_key is SSL2 specific, i.e., obsolete */
-#ifndef OPENSSL_NO_SSL2
-  if ( !add_key_string(list_t, FUNCTOR_session_key1,
-		       session->key_arg_length, session->key_arg) )
-    goto err;
-#endif
-#else
   version = SSL_SESSION_get_protocol_version(session);
   if ( (master_key = PL_malloc(SSL_MAX_MASTER_KEY_LENGTH)) == NULL )
   { SSL_SESSION_free(session);
     return PL_resource_error("memory");
   }
   master_key_length = SSL_SESSION_get_master_key(session, master_key, SSL_MAX_MASTER_KEY_LENGTH);
-#endif
 
   if ( !PL_unify_list_ex(list_t, node_t, list_t) )
     goto err;
@@ -4404,23 +4206,6 @@ pl_ssl_session(term_t stream_t, term_t session_t)
 		       master_key_length, master_key) )
     goto err;
 
-#ifndef HAVE_SSL_GET_CLIENT_RANDOM
-  if ( !add_key_string(list_t, FUNCTOR_session_id1,
-		       session->session_id_length, session->session_id) )
-    goto err;
-
-  if ( ssl->s3 != NULL ) /* If the connection is SSLv2?! */
-  { if ( !add_key_string(list_t, FUNCTOR_client_random1,
-			 SSL3_RANDOM_SIZE, ssl->s3->client_random) )
-      goto err;
-
-    if ( !add_key_string(list_t, FUNCTOR_server_random1,
-			 SSL3_RANDOM_SIZE, ssl->s3->server_random) )
-      goto err;
-  }
-#else
-  /* Note: session_id has no correspondence in OpenSSL >= 1.1.0 */
-
   { unsigned char random[SSL3_RANDOM_SIZE];
 
     SSL_get_client_random(ssl, random, SSL3_RANDOM_SIZE);
@@ -4435,9 +4220,7 @@ pl_ssl_session(term_t stream_t, term_t session_t)
   }
 
   PL_free(master_key);
-#endif
 
-#ifdef HAVE_SSL_CTX_SET_ALPN_PROTOS
   { const unsigned char *data;
     unsigned int len;
     SSL_get0_alpn_selected(ssl, &data, &len);
@@ -4446,7 +4229,6 @@ pl_ssl_session(term_t stream_t, term_t session_t)
       goto err;
     }
   }
-#endif
 
   SSL_SESSION_free(session);
   return PL_unify_nil_ex(list_t);
@@ -4568,12 +4350,7 @@ install_ssl4pl(void)
   ssl_lib_init();
 
   PL_set_prolog_flag("ssl_library_version", PL_ATOM,
-#ifdef HAVE_OPENSSL_VERSION
-		     OpenSSL_version(OPENSSL_VERSION)
-#else
-		     SSLeay_version(SSLEAY_VERSION)
-#endif
-		     );
+		     OpenSSL_version(OPENSSL_VERSION));
 
   PL_set_prolog_flag("system_cacert_filename", PL_ATOM,
 		     SYSTEM_CACERT_FILENAME);
