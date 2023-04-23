--- libhsm/src/bin/hsmutil.c.orig	2022-11-08 08:46:49 UTC
+++ libhsm/src/bin/hsmutil.c
@@ -503,6 +503,7 @@ cmd_dnskey (int argc, char *argv[])
             }
             break;
 #if (LDNS_REVISION >= ((1<<16)|(7<<8)|(0)))
+#if (LDNS_BUILD_CONFIG_USE_ED25519 > 0)
         case LDNS_SIGN_ED25519:
             if (strcmp(key_info->algorithm_name, "EDDSA") != 0) {
                 printf("Not an EDDSA key, the key is of algorithm %s.\n", key_info->algorithm_name);
@@ -521,6 +522,8 @@ cmd_dnskey (int argc, char *argv[])
                 return -1;
             }
             break;
+#endif
+#if (LDNS_BUILD_CONFIG_USE_ED448 > 0)
         case LDNS_SIGN_ED448:
             if (strcmp(key_info->algorithm_name, "EDDSA") != 0) {
                 printf("Not an EDDSA key, the key is of algorithm %s.\n", key_info->algorithm_name);
@@ -539,6 +542,7 @@ cmd_dnskey (int argc, char *argv[])
                 return -1;
             }
             break;
+#endif
 #endif
         default:
             printf("Invalid algorithm: %i\n", algo);
