--- src/show_image.c.orig	Sun Feb  8 04:09:16 1998
+++ src/show_image.c	Wed Jun  3 09:38:49 1998
@@ -13,21 +13,6 @@
 
 extern OUTPUT_PAGE_S *outputPage;
 
-
-/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
-char *truncate(char *string, char endat)
-{
-    char *endchar;
-    
-    
-    if ((string != NULL) && (endchar = strrchr(string, endat)) != NULL)
-       *endchar = '\0';
-       
-    return (string);   
-
-}
-
-
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
 /* 
 ** Display the image after rendering.  Some OS do not allow 
@@ -45,7 +30,7 @@
     
 
     strcpy(temp, pov.input_file_name);
-    sprintf(imgfile, "%s", truncate(temp, '.'));
+    sprintf(imgfile, "%s", strtruncate(temp, '.'));
 
     
     /* 
