
$FreeBSD$

--- ../modules/regex/runmatch.c.orig	Fri Apr 14 17:27:56 2006
+++ ../modules/regex/runmatch.c	Fri Apr 14 17:31:23 2006
@@ -130,7 +130,7 @@
           {
             UINT_8 reg = machine[pc++];
             bound[reg].count++;
-            printf( "-- [%02u] inc r%u [%u,%u] now %u\n",
+            printf( "-- [%02lu] inc r%u [%u,%u] now %u\n",
                     pc-2, reg, bound[reg].min, bound[reg].max,
                     bound[reg].count );
             break;
@@ -149,28 +149,28 @@
 
             save = bound[reg].count;
             printf( "-- [%02u] <%p> boundloop r%u (count %u, [%u,%u])\n", 
-                    pcsave, &subr, reg, save, bound[reg].min, bound[reg].max );
+                    (unsigned int)pcsave, &subr, reg, save, bound[reg].min, bound[reg].max );
 
             if (save < bound[reg].max) {
               result = run_match( str, subr );
               if (result) {
                 printf( "-- [%02u] <%p> boundloop run_match OK\n",
-                        pcsave, &subr );
+                        (unsigned int)pcsave, &subr );
                 return result;
               }
               printf( "-- [%02u] <%p> boundloop run_match failed (fix n=%u)\n",
-                      pcsave, &subr, save );
+                      (unsigned int)pcsave, &subr, save );
               bound[reg].count = save;
               if (save < bound[reg].min) {
                 printf( "-- [%02u] <%p> boundloop total failure w/%u\n",
-                        pcsave, &subr, save );
+                        (unsigned int)pcsave, &subr, save );
                 FAILED;
               }
               printf( "-- [%02u] <%p> boundloop continue w/%u (no match)\n",
-                      pcsave, &subr, save );
+                      (unsigned int)pcsave, &subr, save );
             } else {
               printf( "-- [%02u] <%p> boundloop continue w/%u (hit max)\n",
-                      pcsave, &subr, save );
+                      (unsigned int)pcsave, &subr, save );
             }
             break;
           }
@@ -185,7 +185,7 @@
             bound[reg].max = (machine[pc+2] << 8) + machine[pc+3];
             pc += 4;
             printf( "-- [%02u] setbound r%u [%u,%u]\n",
-                    pcsave, reg, bound[reg].min, bound[reg].max );
+                    (unsigned int)pcsave, reg, bound[reg].min, bound[reg].max );
             break;
           }
 
