--- mtm/mtm_structures.h.orig	2010-07-06 06:21:20.000000000 +0900
+++ mtm/mtm_structures.h	2010-10-25 02:56:43.619561686 +0900
@@ -228,8 +228,6 @@
     MTM_PERMANENT_DATA data;
   } permanent;
   struct {
-  } stclear;
-  struct {
     MTM_STANY_FLAGS flags;
   } stany;
 } MTM_DATA;
