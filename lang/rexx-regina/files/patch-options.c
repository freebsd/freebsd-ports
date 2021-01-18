--- options.c.orig	2019-10-06 06:09:39 UTC
+++ options.c
@@ -125,7 +125,7 @@ void do_options( const tsd_t *TSD, proclevel pl, stren
     */
    if ( get_options_flag( pl, EXT_SINGLE_INTERPRETER ) )
    {
-      setGlobalTSD( TSD );
+      setGlobalTSD( (tsd_t *) TSD );
    }
 }
 
