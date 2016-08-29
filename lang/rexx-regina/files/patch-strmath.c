--- strmath.c.orig	2012-08-09 00:43:53 UTC
+++ strmath.c
@@ -296,7 +296,7 @@ int descr_to_int( const tsd_t *TSD, cons
       streng *h;
 
       h = name_of_node( TSD, NULL, input );
-      fs = tmpstr_of( TSD, h );
+      fs = tmpstr_of( (tsd_t *) TSD, h );
       Free_stringTSD( h );
       switch( errnum )
       {
