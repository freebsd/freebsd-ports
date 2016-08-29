--- options.c.orig	2012-06-11 07:26:33 UTC
+++ options.c
@@ -125,7 +125,7 @@ void do_options( const tsd_t *TSD, procl
     */
    if ( get_options_flag( pl, EXT_SINGLE_INTERPRETER ) )
    {
-      setGlobalTSD( TSD );
+      setGlobalTSD( (tsd_t *) TSD );
    }
 }
 
