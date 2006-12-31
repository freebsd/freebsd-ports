--- r_things.c.orig	Thu Jan 27 00:49:35 2000
+++ r_things.c	Fri Dec 29 20:57:02 2006
@@ -144,7 +144,7 @@
   while (*check != NULL)
     check++;
   
-  numsprites = check-namelist;
+  numsprites = 128;
   
   if (!numsprites)
     return;
