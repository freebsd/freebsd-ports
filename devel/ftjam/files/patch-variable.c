--- variable.c.orig	2006-06-05 12:52:08.000000000 +0200
+++ variable.c	2014-08-07 15:43:50.000000000 +0200
@@ -88,7 +88,7 @@
 	
 	    if( ( val = strchr( *e, '=' ) ) || ( val = *e + strlen( *e ) ) )
 # else
-	    if( val = strchr( *e, '=' ) )
+	    if( ( val = strchr( *e, '=' ) ) )
 # endif
 	    {
 		LIST *l = L0;
@@ -112,11 +112,11 @@
 
 		/* Do the split */
 
-		for( pp = val + 1; p = strchr( pp, split ); pp = p + 1 )
+		for( pp = val + 1; ( p = strchr( pp, split ) ); pp = p + 1 )
 		{
-		    int  len = p - pp;
+		    size_t len = p - pp;
 
-		    if ( len >= sizeof(buf) )
+		    if ( ( len >= sizeof(buf) ) )
 		      len = sizeof(buf)-1;
 
 		    strncpy( buf, pp, len );
@@ -203,7 +203,7 @@
 
 		    /* Separate with space */
 
-		    if( l = list_next( l ) )
+		    if( ( l = list_next( l ) ) )
 		    *out++ = ' ';
 		}
 
