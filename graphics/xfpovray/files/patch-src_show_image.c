--- src/show_image.c	1998-02-07 22:09:16.000000000 -0500
+++ src/show_image.c	2015-03-09 00:55:58.000000000 -0400
@@ -2,7 +2,8 @@
 #include <stddef.h>
 #include <string.h>
 
-#include "forms.h"
+#include <forms.h>
+#include "flx.h"
 #include "xfpovray.h"
 
 extern struct pov_options pov;
@@ -13,21 +14,6 @@
 
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
@@ -45,7 +31,7 @@
     
 
     strcpy(temp, pov.input_file_name);
-    sprintf(imgfile, "%s", truncate(temp, '.'));
+    sprintf(imgfile, "%s", strtruncate(temp, '.'));
 
     
     /* 
@@ -63,7 +49,7 @@
     strcat(imgfile, ext);
     
     sprintf(currentFilter, "*%s", ext);
-    file = (char *) flx_filebox (CONFIG_POV_DIR, currentFilter, &imgfile); 
+    file = flx_filebox (CONFIG_POV_DIR, currentFilter, imgfile); 
 
     if (strcmp(file, "") != 0) {
        sprintf(viewit, "%s %s &", CONFIG_DISPLAY_COMMAND, imgfile);
