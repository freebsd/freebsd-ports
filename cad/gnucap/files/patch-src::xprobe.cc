--- src/u_xprobe.cc.orig	Tue Mar 26 18:20:27 2002
+++ src/u_xprobe.cc	Sun Dec 22 09:17:33 2002
@@ -25,7 +25,7 @@
 #include "u_opt.h"
 #include "u_xprobe.h"
 /*--------------------------------------------------------------------------*/
-double XPROBE::operator()(mod_t m=mtNONE, bool db = false)const
+double XPROBE::operator()(mod_t m, bool db)const
 {
   {if (OK()){
     if (m == mtNONE) {
