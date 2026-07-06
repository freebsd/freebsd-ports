--- src/mongo/util/net/openssl_init.cpp.orig	2026-06-16 14:14:04 UTC
+++ src/mongo/util/net/openssl_init.cpp
@@ -242,24 +242,6 @@ MONGO_INITIALIZER_GENERAL(SetupOpenSSL, ("default"), (
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
         }
 #endif
     }
