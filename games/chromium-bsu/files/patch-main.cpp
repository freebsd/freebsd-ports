--- src/main.cpp.orig	Fri Mar 14 21:01:12 2003
+++ src/main.cpp	Fri Mar 14 21:01:12 2003
@@ -109,10 +109,6 @@
 		}
 	}
 	
-#ifdef PKGDATADIR
-	strcpy(dataDir, PKGDATADIR);
-	strcat(dataDir, "/data");
-#else	
 	char *chromData = getenv("CHROMIUM_DATA");
 	if(chromData)
 		strcpy(dataDir, chromData);
@@ -121,7 +117,7 @@
 		#ifdef macintosh
 		strcpy(dataDir, "::data");	
 		#else
-		strcpy(dataDir, "../data");	
+		strcpy(dataDir, CHROMIUM_DATA_DIR);	
 		#endif
 		fprintf(stderr, "!!\n");
 		fprintf(stderr, "!! WARNING - CHROMIUM_DATA environment variable is not set!\n");
@@ -131,7 +127,6 @@
 		fprintf(stderr, "!! 		  (using %s)\n", dataDir);
 		fprintf(stderr, "!!\n");
 	}
-#endif
 
 	srand(time(NULL));
 	
