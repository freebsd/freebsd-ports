--- src/rgbadraw.c.orig	Sat Jul 31 11:10:28 2004
+++ src/rgbadraw.c	Sat Jul 31 11:16:05 2004
@@ -2357,14 +2357,14 @@
                        /* last span on line and still not < ss->x */
                        if (ps)
                           ps->next = s;
-                     nospans:
+                     nospans: ;
                     }
                }
              if (i == y2)
                 goto nolines;
              i += step;
           }
-      nolines:
+      nolines: ;
      }
    for (i = 0; i < h; i++)
      {
