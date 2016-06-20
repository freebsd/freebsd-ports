--- src/libsphinx2/include/pconf.h.orig	2001-12-13 21:11:27 UTC
+++ src/libsphinx2/include/pconf.h
@@ -124,4 +124,4 @@ int ppconf(int argc, char *argv[],
 	   char * (*GetDefault)(char const *, char const *), char last);
 void pusage(char *prog, Config_t *cp);
 
-#endif _PCONF_
+#endif
