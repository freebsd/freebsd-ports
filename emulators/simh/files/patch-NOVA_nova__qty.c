--- NOVA/nova_qty.c.orig	2016-12-01 22:43:42 UTC
+++ NOVA/nova_qty.c
@@ -603,11 +603,12 @@ t_stat qty_common_svc( DIB * dibp, UNIT 
 
     ++qty_polls ;                                       /*  another time 'round the track  */
     newln = tmxr_poll_conn( &qty_desc ) ;               /*  anybody knocking at the door?  */
-    if ( (newln >= 0) && qty_mdm )
+    if ( (newln >= 0) && qty_mdm ) {
         if ( newln >= qty_max )
         {
         return SCPE_IERR;                               /*  WTF - sanity check failed, over?  */
         }
+      }
     else
         {
         line = newln ;                                  /*  handle modem control  */
@@ -991,7 +992,7 @@ int32 alm( int32 pulse, int32 code, int3
         break ;
 
     case ioDIC :    /*  get modem or receiver status  */
-        if ( alm_line < qty_max )
+        if ( alm_line < qty_max ) {
             if ( alm_section )
             {
             /*  get modem section status  */
@@ -1000,6 +1001,7 @@ int32 alm( int32 pulse, int32 code, int3
                 iodata = 0035 ;                         /*  set CD, CTS, DSR, MDM flags  */
                 }
             }
+          }
         else
             {
             /*  get receiver section status  */
