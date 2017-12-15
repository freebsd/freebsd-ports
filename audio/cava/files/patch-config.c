--- config.c.orig	2017-08-26 08:52:40 UTC
+++ config.c
@@ -378,7 +378,7 @@ if (p->smcount > 0) {
 	iniparser_getseckeys(ini, "eq", keys);
 	#endif
 	#ifdef LEGACYINIPARSER
-	char **keys = iniparser_getseckeys(ini, "eq");
+	char **keys = iniparser_getseckeys(ini, "eq", keys);
 	#endif
 	for (int sk = 0; sk < p->smcount; sk++) {
 		p->smooth[sk] = iniparser_getdouble(ini, keys[sk], 1);
