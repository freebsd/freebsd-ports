--- ccx_1.0/src/ccx_1.0.c.orig	Sun Jun 22 00:33:19 2003
+++ ccx_1.0/src/ccx_1.0.c	Sun Jun 22 00:41:18 2003
@@ -694,6 +694,8 @@
 	  mastruct(&nk,kon,ipkon,lakon,&ne,nodeboun,ndirboun,&nboun,ipompc,
 		   nodempc,&nmpc,nactdof,icol,jq,&mast1,&irow,&isolver,&neq,nnn,
 		   ikmpc,ilmpc,ikcol,ipointer,&nsky,&nzs,&nmethod);
+      } else {
+	    neq = 1;
       }
   }
   else{
