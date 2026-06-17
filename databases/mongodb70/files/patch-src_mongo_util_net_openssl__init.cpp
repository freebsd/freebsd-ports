--- src/mongo/util/net/openssl_init.cpp.orig	2026-06-17 14:19:16 UTC
+++ src/mongo/util/net/openssl_init.cpp
@@ -230,37 +230,9 @@ MONGO_INITIALIZER_GENERAL(SetupOpenSSL, ("default"), (
         setupFIPS();
     } else {
 #if OPENSSL_VERSION_NUMBER > 0x30000000L
-        // When the OpenSSL 3 FIPS provider is disabled, OpenSSL uses a primary DRBG
-        // to seed per-thread DRBGs. The primary DRBG relies on the system entropy source for
-        // seeding and reseeding. In highly concurrent environments where many threads are
-        // being spawned at once, the primary DRBG will receive many generate requests to
-        // seed all the new threads. Both the reseed request and
-        // the time intervals can be tuned via startup server parameters in response to
-        // observed performance regressions.
-        EVP_RAND_CTX* primary = RAND_get0_primary(NULL /* default OSSL_LIB_CTX */);
-        if (primary == NULL) {
             LOGV2_WARNING(12549200,
                           "Unable to fetch primary DRBG to adjust reseed parameters, continuing "
                           "with OpenSSL defaults");
-        } else {
-            auto primaryReseedRequestsInterval =
-                static_cast<unsigned int>(crypto::opensslPrimaryDRBGReseedMaxRequests);
-            auto primaryReseedTimeInterval =
-                static_cast<time_t>(crypto::opensslPrimaryDRBGReseedMaxTime);
-            OSSL_PARAM params[3] = {
-                OSSL_PARAM_construct_uint(OSSL_DRBG_PARAM_RESEED_REQUESTS,
-                                          &primaryReseedRequestsInterval),
-                OSSL_PARAM_construct_time_t(OSSL_DRBG_PARAM_RESEED_TIME_INTERVAL,
-                                            &primaryReseedTimeInterval),
-                OSSL_PARAM_END};
-            if (!EVP_RAND_CTX_set_params(primary, params)) {
-                LOGV2_WARNING(12549201,
-                              "Unable to reset primary DRBG reseed parameters, continuing with "
-                              "OpenSSL defaults",
-                              "error"_attr =
-                                  SSLManagerInterface::getSSLErrorMessage(ERR_get_error()));
-            }
-        }
 #endif
     }
 
