--- search.c.orig	2014-08-07 15:30:23.000000000 +0200
+++ search.c	2014-08-07 15:30:50.000000000 +0200
@@ -34,7 +34,7 @@
 	f->f_grist.ptr = 0;
 	f->f_grist.len = 0;
 
-	if( varlist = var_get( "LOCATE" ) )
+	if( ( varlist = var_get( "LOCATE" ) ) )
 	{
 	    f->f_root.ptr = varlist->string;
 	    f->f_root.len = strlen( varlist->string );
@@ -48,7 +48,7 @@
 
 	    return newstr( buf );
 	}
-	else if( varlist = var_get( "SEARCH" ) )
+	else if( ( varlist = var_get( "SEARCH" ) ) )
 	{
 	    while( varlist )
 	    {
