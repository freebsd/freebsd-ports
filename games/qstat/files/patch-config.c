--- config.c.orig	Fri Nov  8 19:06:04 2002
+++ config.c	Fri Feb 14 13:07:09 2003
@@ -204,7 +204,7 @@
     filename= getenv( "HOME");
     if ( filename != NULL && filename[0] != '\0')  {
 	char path[1024];
-	sprintf( path, "%s/%s", filename, HOME_CONFIG_FILE);
+	snprintf( path, (sizeof(path) -1),"%s/%s", var, HOME_CONFIG_FILE);
     }
 /* 1. $QSTAT_CONFIG
    2. UNIX: $HOME/.qstatrc         WIN: $HOME/qstat.cfg
