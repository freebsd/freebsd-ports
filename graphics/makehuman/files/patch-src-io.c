--- src/io.c.orig	Mon Mar  6 12:18:00 2006
+++ src/io.c	Mon Mar  6 12:19:50 2006
@@ -409,6 +409,7 @@
     util = strtok (NULL, token);
     value = atof(util);
 
+    {
 #ifdef HAVE_CONFIG_H
     char tmp[MAX_PATH];
     strcpy (tmp, PACKAGE_DATA_DIR"/");
@@ -422,6 +423,7 @@
       display();
     }
     //printf("Eccoci\n");
+    }
 
   }
 
