--- r_things.c.orig	2000-01-26 23:49:35 UTC
+++ r_things.c
@@ -144,7 +144,7 @@ void R_InitSpriteDefs (char **namelist)
   while (*check != NULL)
     check++;
   
-  numsprites = check-namelist;
+  numsprites = 128;
   
   if (!numsprites)
     return;
