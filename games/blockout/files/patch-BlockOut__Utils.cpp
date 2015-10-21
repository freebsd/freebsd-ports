--- BlockOut/Utils.cpp.orig	2014-05-06 16:47:55.000000000 +0700
+++ BlockOut/Utils.cpp	2015-08-17 10:34:51.000000000 +0600
@@ -207,11 +207,9 @@
     return FALSE;
   }
     
-  char *blockoutHome = getenv("BL2_HOME");
+  const char *blockoutHome = getenv("BL2_HOME");
   if( blockoutHome==NULL ) {
-    printf("BL2_HOME environement variable if not defined !\n");
-    printf("Please set the BL2_HOME to the BlockOut II installation directory (ex: BL2_HOME=/usr/local/bl2).\n");
-    return FALSE;
+    blockoutHome="%%DATADIR%%";
   }
   strcpy( bl2Home , blockoutHome );
     
