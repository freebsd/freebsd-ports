--- src/xfpovray.c	1998-02-22 22:35:14.000000000 -0500
+++ src/xfpovray.c	2015-03-09 02:07:44.000000000 -0400
@@ -33,9 +33,11 @@
 **-
 ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
-
+#include <errno.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <unistd.h>
+#include <sys/stat.h>
 
 #include "forms.h"
 #include "xfpovray.h"
@@ -47,7 +48,7 @@
 #include "xfpovray.xpm"
 
 
-#if FL_VERSION < MIN_XFORMS_VER || FL_REVISION < MIN_XFORMS_REV
+#if FL_VERSION < MIN_XFORMS_VER || (FL_VERSION == MIN_XFORMS_VER && FL_REVISION < MIN_XFORMS_REV)
 #error
 #error CANNOT COMPILE WITH THIS VERSION OF XFORMS.
 #error PLEASE UPGRADE TO THE LATEST VERSION.
@@ -158,7 +159,7 @@
 int main (int argc, char **argv)
 {
  
-    FL_OBJECT *obj, *ret;
+    FL_OBJECT *ret;
     int version, revision;
     static char *home;
     FILE *fp;
@@ -259,26 +260,33 @@
      
     /* Check for directory $HOME/.xfpovray */
     if ((fp = fopen(TEMP_FILE, "w")) == NULL) {
-   
-       temp = (char *) fl_calloc (1, strlen(MKDIR) + strlen(" ") + 
-           strlen(home) + strlen("/.xfpovray") + 1); 
-       sprintf (temp, "%s %s/.xfpovray", MKDIR, home);
-       system (temp);
-       free (temp);
-
-       temp = (char *) fl_calloc (1, 
-	   strlen("\nWelcome to xfpovray!\nCreated directory ") + 
-	   strlen(home) + strlen("/.xfpovray") +
-	   strlen("\n\nCheck your setup with\nOptions->Configure") + 
-	   + 1); 
-       sprintf (temp, 
-           "\nWelcome to xfpovray!\nCreated directory %s/.xfpovray\n\nCheck your setup with\nOptions->Configure",
-	    home);
-       flx_set_dialog_font (FL_BOLD_STYLE, FL_NORMAL_SIZE);
+       int success;
+
+       if (errno != ENOTDIR && errno != ENOENT) {
+           success = 0;
+       } else { 
+           temp = fl_calloc (1, strlen(home) + strlen("/.xfpovray") + 1);
+           sprintf (temp, "%s/.xfpovray", home);
+           success = mkdir(temp, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == 0;
+           free (temp);
+       }
+       if (success)
+           asprintf(&temp, "Welcome to xfpovray!\n"
+               "Created directory %s/.xfpovray\n\n"
+	       "Check your setup with\nOptions->Configure",
+		    home);
+       else
+           asprintf(&temp, "Welcome to xfpovray!\n"
+               "Directory %s/.xfpovray inoperable:\n\n%s\n\n"
+	       "Please, resolve the problem and restart",
+		    home, strerror(errno));
+       flx_set_dialog_font (FL_NORMAL_STYLE, FL_NORMAL_SIZE);
        flx_show_dialog ("message", temp);
        free (temp);   
-       fclose (fp);
-    }
+    } else {
+       fclose(fp);
+       unlink(TEMP_FILE);
+    }
 
     /* 
     ** Build the various forms 
@@ -414,9 +420,7 @@
 
 	/* Check for external routines */
 	home = getenv("HOME");
-        temp = (char *) fl_calloc (1, 
-	    strlen(home) + strlen(".xfpovray/external.routines") + 1); 
-	sprintf(temp, "%s/.xfpovray/external.routines", home);
+	asprintf(&temp, "%s/.xfpovray/external.routines", home);
 	if ((ext = fopen(temp, "r")) != NULL) {
            
            /* Callback key is the menu item number of the first added
