--- config.c.orig	2014-03-01 01:49:37 UTC
+++ config.c
@@ -192,14 +192,7 @@ qsc_load_default_config_files()
 
     var= getenv( "HOME");
     if ( var != NULL && var[0] != '\0')  {
-	int len= strlen(var);
-	if ( len > 900)
-	    len= 900;
-	strncpy( path, var, len);
-	path[len]= '\0';
-	strcat( path, "/");
-	strcat( path, HOME_CONFIG_FILE);
-/*	sprintf( path, "%s/%s", var, HOME_CONFIG_FILE); */
+	snprintf( path, sizeof(path), "%s/%s", var, HOME_CONFIG_FILE);
 	rc= try_load_config_file( path, 0);
 	if ( rc == 0 || rc == -1)
 	    return rc;
