--- libhsm/src/lib/libhsm.c.orig	2022-11-08 08:46:49 UTC
+++ libhsm/src/lib/libhsm.c
@@ -2175,13 +2175,17 @@ hsm_sign_buffer(hsm_ctx_t *ctx,
                                             sign_buf);
             break;
 #if (LDNS_REVISION >= ((1<<16)|(7<<8)|(0)))
+#if (LDNS_BUILD_CONFIG_USE_ED25519 > 0)
         case LDNS_SIGN_ED25519:
             data_direct = 1;
             break;
+#endif
+#if (LDNS_BUILD_CONFIG_USE_ED448 > 0)
         case LDNS_SIGN_ED448:
             data_direct = 1;
             break;
 #endif
+#endif
         default:
             /* log error? or should we not even get here for
              * unsupported algorithms? */
@@ -2225,12 +2229,16 @@ hsm_sign_buffer(hsm_ctx_t *ctx,
             sign_mechanism.mechanism = CKM_ECDSA;
             break;
 #if (LDNS_REVISION >= ((1<<16)|(7<<8)|(0)))
+#ifdef LDNS_BUILD_CONFIG_ED25519
         case LDNS_SIGN_ED25519:
             sign_mechanism.mechanism = CKM_EDDSA;
             break;
+#endif
+#ifdef LDNS_BUILD_CONFIG_ED448
         case LDNS_SIGN_ED448:
             sign_mechanism.mechanism = CKM_EDDSA;
             break;
+#endif
 #endif
         default:
             /* log error? or should we not even get here for
