--- src/simutrans/sys/simsys.cc.orig	2024-05-04 14:27:27 UTC
+++ src/simutrans/sys/simsys.cc
@@ -526,9 +526,9 @@ char const *dr_query_homedir()
 	}
 #else
 	if( getenv("XDG_DATA_HOME") == NULL ) {
-		sprintf(buffer, "%s/simutrans", getenv("HOME"));
+		sprintf(buffer, "%s/.simutrans", getenv("HOME"));
 	} else {
-		sprintf(buffer, "%s/simutrans", getenv("XDG_DATA_HOME"));
+		sprintf(buffer, "%s/.simutrans", getenv("XDG_DATA_HOME"));
 	}
 #endif
 
