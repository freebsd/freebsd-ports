--- sw/source/core/unocore/unotbl.cxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ sw/source/core/unocore/unotbl.cxx	2014-02-25 12:20:50.000000000 -0500
@@ -692,7 +692,7 @@
 
 /*  non UNO function call to set string in SwXCell */
 void sw_setString( SwXCell &rCell, const OUString &rTxt,
-        sal_Bool bKeepNumberFmt )
+        sal_Bool bKeepNumberFmt = sal_False )
 {
     if(rCell.IsValid())
     {
