--- vp88.c.orig	Wed Dec 29 20:06:45 2004
+++ vp88.c	Wed Dec 29 21:04:35 2004
@@ -530,9 +530,9 @@
 
 if(ifansi== IDM_3DIM)
   {
-  gcvt(rotx,idigit,crotx);
-  gcvt(roty,idigit,croty);
-  gcvt(rotz,idigit,crotz);
+  snprintf(crotx, idigit, "%g", rotx);
+  snprintf(croty, idigit, "%g", roty);
+  snprintf(crotz, idigit, "%g", rotz);
   strcpy(crx,"ROTX= ");
   strcpy(cry,"ROTY= ");
   strcpy(crz,"ROTZ= ");
