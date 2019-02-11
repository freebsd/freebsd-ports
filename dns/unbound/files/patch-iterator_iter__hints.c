--- iterator/iter_hints.c.orig	2018-08-09 12:44:40 UTC
+++ iterator/iter_hints.c
@@ -252,7 +252,7 @@ read_stubs_addr(struct config_stub* s, struct delegpt*
 				s->name, p->str);
 			return 0;
 		}
-#ifndef HAVE_SSL_SET1_HOST
+#if ! defined(HAVE_SSL_SET1_HOST) && ! defined(HAVE_X509_VERIFY_PARAM_SET1_HOST)
 		if(auth_name)
 			log_err("no name verification functionality in "
 				"ssl library, ignored name for %s", p->str);
