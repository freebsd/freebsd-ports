--- BlockOut/Utils.cpp.orig	2008-01-09 21:29:06.000000000 +0300
+++ BlockOut/Utils.cpp	2014-12-02 07:58:58.452013513 +0300
@@ -162,11 +162,9 @@
 		return FALSE;
 	}
 		
-	char *blockoutHome = getenv("BL2_HOME");
+	const char *blockoutHome = getenv("BL2_HOME");
 	if( blockoutHome==NULL ) {
-	  printf("BL2_HOME environement variable if not defined !\n");
-	  printf("Please set the BL2_HOME to the BlockOut II installation directory (ex: BL2_HOME=/usr/local/bl2).\n");
-		return FALSE;
+		blockoutHome="%%DATADIR%%";
 	}
 	strcpy( bl2Home , blockoutHome );
 		
