--- cb88o.c.orig	2010-01-19 10:23:29.000000000 +0000
+++ cb88o.c	2010-01-19 10:28:02.000000000 +0000
@@ -1161,9 +1161,9 @@
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
@@ -1231,9 +1231,9 @@
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
@@ -1306,7 +1306,7 @@
 /*---------------------------------------------------------------------------
 * beim allerersten Start geht zm mit -100. rein
 *--------------------------------------------------------------------------*/
-gcvt(zm,idigit,czm); 
+snprintf(czm, idigit, "%g", zm); 
 
 if(LANG == 1) strcpy(cstring,"Z-Limit zum Betrachter");
 if(LANG == 2) strcpy(cstring,"Z Limit towards you");
