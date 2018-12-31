--- src/z88o/unix/cb88o.c.orig	2018-12-05 16:59:00 UTC
+++ src/z88o/unix/cb88o.c
@@ -1164,9 +1164,9 @@ const gchar *ccx,*ccy,*ccz;
 /*---------------------------------------------------------------------------
 * beim allerersten Start gehen fux, fuy & fuz mit je 100. rein
 *--------------------------------------------------------------------------*/
-gcvt(fux,idigit,cfux); 
-gcvt(fuy,idigit,cfuy); 
-gcvt(fuz,idigit,cfuz); 
+snprintf(cfux, idigit, "%g", fux);
+snprintf(cfuy, idigit, "%g", fuy);
+snprintf(cfuz, idigit, "%g",cfuz);
 
 if(LANG == 1) strcpy(cstring,"VERGROESSERUNG VER.");
 if(LANG == 2) strcpy(cstring,"MAGNIFICATION DEFL.");
@@ -1234,9 +1234,9 @@ const gchar *ccx,*ccy,*ccz;
 /*---------------------------------------------------------------------------
 * beim allerersten Start gehen rotx, roty & rotz mit je 0. rein
 *--------------------------------------------------------------------------*/
-gcvt(rotx,idigit,crotx); 
-gcvt(roty,idigit,croty); 
-gcvt(rotz,idigit,crotz); 
+snprintf(crotx, idigit, "%g", rotx);
+snprintf(croty, idigit, "%g", roty);
+snprintf(crotz, idigit, "%g", rotz);
 
 if(LANG == 1) strcpy(cstring,"ROTATIONEN 3-D");
 if(LANG == 2) strcpy(cstring,"ROTATIONS 3-D");
@@ -1307,7 +1307,7 @@ const gchar *ccm;
 /*---------------------------------------------------------------------------
 * beim allerersten Start geht zm mit -100. rein
 *--------------------------------------------------------------------------*/
-gcvt(zm,idigit,czm); 
+snprintf(czm, idigit, "%g", zm); 
 
 if(LANG == 1) strcpy(cstring,"Z-Limit zum Betrachter");
 if(LANG == 2) strcpy(cstring,"Z Limit towards you");
