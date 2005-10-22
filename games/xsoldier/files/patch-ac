
$FreeBSD$

--- main.c.orig
+++ main.c
@@ -33,7 +33,6 @@
 /* DeleteAllStar */
 #include "star.h"
 #include "score.h"
-#include "wait.h"
 #include "graphic.h"
 #include "input.h"
 
@@ -175,7 +174,7 @@
                         i + 1);
                 display[sizeof(display) - 1] = '\0';
                 fprintf(stderr, "truncated to %d chars\n",
-                        sizeof(display) - 1);
+                        (int)sizeof(display) - 1);
               }
               i++;
             }
