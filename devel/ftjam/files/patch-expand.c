--- expand.c.orig	2014-08-07 15:13:43.000000000 +0200
+++ expand.c	2014-08-07 15:16:26.000000000 +0200
@@ -83,7 +83,7 @@
 	int depth;
 
 	if( DEBUG_VAREXP )
-	    printf( "expand '%.*s'\n", end - in, in );
+	    printf( "expand '%.*s'\n", (int)(end - in), in );
 
 	/* This gets alot of cases: $(<) and $(>) */
 
@@ -210,7 +210,7 @@
 
 		strcpy( varname, vars->string );
 
-		if( colon = strchr( varname, MAGIC_COLON ) )
+		if( ( colon = strchr( varname, MAGIC_COLON ) ) )
 		{
 		    *colon = '\0';
 		    var_edit_parse( colon + 1, &edits );
@@ -220,11 +220,11 @@
 		/* sub1 is x (0 default) */
 		/* sub2 is length (-1 means forever) */
 
-		if( bracket = strchr( varname, MAGIC_LEFT ) )
+		if( ( bracket = strchr( varname, MAGIC_LEFT ) ) )
 		{
 		    char *dash;
 
-		    if( dash = strchr( bracket + 1, '-' ) )
+		    if( ( dash = strchr( bracket + 1, '-' ) ) )
 			*dash = '\0';
 
 		    sub1 = atoi( bracket + 1 ) - 1;
@@ -454,7 +454,7 @@
 		fp->ptr = "";
 		fp->len = 0;
 	    }
-	    else if( p = strchr( mods, MAGIC_COLON ) )
+	    else if( ( p = strchr( mods, MAGIC_COLON ) ) )
 	    {
 		*p = 0;
 		fp->ptr = ++mods;
@@ -544,7 +544,7 @@
 var_edit_quote( char  *out )
 {
   /* Handle quoting now */
-  int    count, len;
+  int    count;
   char*  p = out;
   char*  q;
 
