--- modules/src/frboutmodule/glxutil.c.orig
+++ modules/src/frboutmodule/glxutil.c
@@ -53,12 +53,12 @@
   Colormap cmap;
   int AttributeList[] = {GLX_RGBA, GLX_DOUBLEBUFFER, None};
   XSetWindowAttributes swa;
+  const char* display_name_ptr;
 
   s_xsize = xres;
   s_ysize = yres;
 
   // open a new connection to the X server
-  const char* display_name_ptr;
   if (strcmp(display_name,"default")==0)
     display_name_ptr=0; // use the DISPLAY environment variable
   else
