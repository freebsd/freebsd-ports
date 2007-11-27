--- XMotif/lines.c.orig	1992-10-07 04:16:16.000000000 +0100
+++ XMotif/lines.c	2007-11-23 22:16:24.000000000 +0100
@@ -154,10 +154,13 @@
    int number_of_lines=sl->num_lines;
    ComponentPair *comp_pairs=sl->comp_pairs;
    register int i;
+   MComponent *tmp;
 
-   if (comp2<comp1) 
-      swap((caddr_t)comp1,(caddr_t)comp2);
-
+   if (comp2<comp1) {
+      tmp = comp2;
+      comp2 = comp1;
+      comp1 = tmp;
+   }
 
    for (i = 0; i < number_of_lines; ++i) {
       if ((comp_pairs[i].comp1 == comp1) &&
