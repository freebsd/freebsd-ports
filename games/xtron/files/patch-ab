--- resource.c.orig	Mon Apr 24 07:39:03 1995
+++ resource.c	Fri Mar 31 23:09:37 2000
@@ -101,8 +101,8 @@
       if ((XTRONresources = XrmGetFileDatabase("./.xtronrc")) == NULL)  {
 	 if ((XTRONresources = XrmGetFileDatabase("$HOME/xtronrc")) == NULL)  {
 	    if ((XTRONresources = XrmGetFileDatabase("$HOME/.xtronrc")) == NULL)  {
-	       if ((XTRONresources = XrmGetFileDatabase("/usr/X11/lib/X11/app-defaults/xtronrc")) == NULL)  {
-		  if ((XTRONresources = XrmGetFileDatabase("/usr/X11/lib/X11/app-defaults/.xtronrc")) == NULL)  {
+	       if ((XTRONresources = XrmGetFileDatabase(PREFIX "/lib/X11/app-defaults/Tron")) == NULL)  {
+		  if ((XTRONresources = XrmGetFileDatabase(PREFIX "/share/xtron/xtronrc")) == NULL)  {
 		     fprintf(stderr,"error: unable to open/read resource file xtronrc\n");
 		     return(0);
 		  }
