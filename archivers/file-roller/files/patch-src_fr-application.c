--- src/fr-application.c.orig	2018-07-16 20:15:42 UTC
+++ src/fr-application.c
@@ -42,7 +42,6 @@
 #define SERVICE_TIMEOUT 10
 
 
-gint                ForceDirectoryCreation;
 static char       **remaining_args;
 static char        *arg_add_to = NULL;
 static int          arg_add = FALSE;
