--- config.c.orig	Tue Aug  6 21:13:34 2002
+++ config.c	Sun Sep 22 09:00:30 2002
@@ -157,7 +157,7 @@
 
     var= getenv( "HOME");
     if ( var != NULL && var[0] != '\0')  {
-	sprintf( path, "%s/%s", var, HOME_CONFIG_FILE);
+	snprintf( path, (sizeof(path) -1),"%s/%s", var, HOME_CONFIG_FILE);
 	rc= try_load_config_file( path, 0);
 	if ( rc == 0 || rc == -1)
 	    return rc;
@@ -197,7 +197,7 @@
     filename= getenv( "HOME");
     if ( filename != NULL && filename[0] != '\0')  {
 	char path[1024];
-	sprintf( path, "%s/%s", filename, HOME_CONFIG_FILE);
+	snprintf( path, (sizeof(path) -1),"%s/%s", var, HOME_CONFIG_FILE);
     }
 /* 1. $QSTAT_CONFIG
    2. UNIX: $HOME/.qstatrc         WIN: $HOME/qstat.cfg
