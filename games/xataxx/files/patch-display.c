--- display.c.orig
+++ display.c
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <math.h>
@@ -145,7 +147,7 @@
   int occ,x,y;
 
   if (currdpy != dpy && !botmode)
-    return;
+    return(0);
   wipemap(currdpy, currbamp, currgc, currscr, currwin);
   for (y=0;y!=ysize;y++)
     for (x=0;x!=xsize;x++)
@@ -386,7 +388,7 @@
       XFlush(currdpy);
     }
     XNextEvent(dpy,&event);
-    return;
+    return(0);
   }
 }
 
