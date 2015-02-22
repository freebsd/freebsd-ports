--- examples/ldns-signzone.c.orig	2014-01-10 21:04:41 UTC
+++ examples/ldns-signzone.c
@@ -470,6 +470,7 @@ main(int argc, char *argv[])
 		case 'A':
 			signflags |= LDNS_SIGN_DNSKEY_WITH_ZSK;
 			break;
+#ifdef HAVE_ENGINE_LOAD_CRYPTODEV
 		case 'E':
 			ENGINE_load_builtin_engines();
 			ENGINE_load_dynamic();
@@ -494,6 +495,7 @@ main(int argc, char *argv[])
 				ENGINE_set_default(engine, 0);
 			}
 			break;
+#endif
 		case 'k':
 			eng_key_l = strchr(optarg, ',');
 			if (eng_key_l && strlen(eng_key_l) > 1) {
