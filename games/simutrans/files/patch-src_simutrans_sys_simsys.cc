--- src/simutrans/sys/simsys.cc.orig	2024-12-29 01:27:00 UTC
+++ src/simutrans/sys/simsys.cc
@@ -562,10 +562,10 @@ char const *dr_query_homedir()
 	int maxlen = PATH_MAX + 22;
 	unsigned n;
 	if( getenv("XDG_DATA_HOME") == NULL ) {
-		n = snprintf(buffer, maxlen, "%s/simutrans", getenv("HOME"));
+		n = snprintf(buffer, maxlen, "%s/.simutrans", getenv("HOME"));
 	}
 	else {
-		n = snprintf(buffer, maxlen, "%s/simutrans", getenv("XDG_DATA_HOME"));
+		n = snprintf(buffer, maxlen, "%s/.simutrans", getenv("XDG_DATA_HOME"));
 	}
 	if (n >= maxlen) {
 		return NULL;
