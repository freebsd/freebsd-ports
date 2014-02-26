--- sw/inc/unotbl.hxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ sw/inc/unotbl.hxx	2014-02-25 12:20:50.000000000 -0500
@@ -71,7 +71,7 @@
     public SwClient
 {
     friend void   sw_setString( SwXCell &rCell, const OUString &rTxt,
-                                 sal_Bool bKeepNumberFmt = sal_False );
+                                 sal_Bool bKeepNumberFmt );
     friend double sw_getValue( SwXCell &rCell );
     friend void   sw_setValue( SwXCell &rCell, double nVal );
 
