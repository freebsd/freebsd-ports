--- cartridge.c.orig	Wed Dec 17 03:26:30 2003
+++ cartridge.c	Thu Dec 25 21:36:47 2003
@@ -772,7 +772,7 @@
 
 void CARTStateRead( void )
 {
-    int savedCartType = CART_NONE;;
+    int savedCartType = CART_NONE;
     UWORD namelen;
     FILE *fp;
     char filename[FILENAME_MAX];
