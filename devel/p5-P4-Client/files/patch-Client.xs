--- ../P4-Client-2.2596/Client.xs	Tue Oct 15 16:22:15 2002
+++ Client.xs	Tue Sep  2 09:45:09 2003
@@ -131,7 +131,7 @@ static int GetFlag( const char *flag, SV
 	    warn( "Can't dereference object!!!" );
 	    return 0;
 	}
-	tmp = hv_fetch( (HV *)SvRV(obj), flag, strlen( flag ), 0 );
+	tmp = hv_fetch( (HV *)SvRV(obj), (char *)flag, strlen( flag ), 0 );
 	if ( ! tmp ) return 0;
 	return SvIV( *tmp );
 }
