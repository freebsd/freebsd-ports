
$FreeBSD$

--- manage.c.orig
+++ manage.c
@@ -17,7 +17,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 /*
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
@@ -393,7 +392,7 @@
 
     New = (PlayerData *)malloc(sizeof(PlayerData));
 
-    sprintf(New->Rec[0].name,name);
+    snprintf(New->Rec[0].name, sizeof(New->Rec[0].name), name);
     New->Rec[0].score = 0;
     New->Rec[0].stage = 0;
     New->Rec[0].loop = 0;
