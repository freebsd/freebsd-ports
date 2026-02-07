--- strmath.c.orig	2019-10-06 06:09:40 UTC
+++ strmath.c
@@ -296,7 +296,7 @@ int descr_to_int( const tsd_t *TSD, const num_descr *i
       streng *h;
 
       h = name_of_node( TSD, NULL, input );
-      fs = tmpstr_of( TSD, h );
+      fs = tmpstr_of( (tsd_t *) TSD, h );
       Free_stringTSD( h );
       switch( errnum )
       {
