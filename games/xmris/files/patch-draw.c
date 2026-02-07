--- draw.c.orig	1995-12-22 12:07:19 UTC
+++ draw.c
@@ -1030,14 +1030,14 @@ ARGSEP  char CONST *parent
 	      stream = fopen(filename, "r");
 	    }
 	  if(!stream)
-	    /*{{{  try in app-defaults/xmris/<file>*/
+	    /*{{{  try in xmris/<file>*/
 	    {
 	      char CONST *lib;
 	      
 	      lib = XtResolvePathname(display.display,
-		  "app-defaults/xmris", name, NULL, NULL, NULL, 0, NULL);
+		  "xmris", name, NULL, NULL, NULL, 0, NULL);
 	      if(!lib)
-		lib = XtResolvePathname(display.display, "app-defaults/xmris",
+		lib = XtResolvePathname(display.display, "xmris",
 		    name, FILE_SUFFIX, NULL, NULL, 0, NULL);
 	      if(!lib && data.dir)
 		lib = XtResolvePathname(display.display, data.dir, name,
