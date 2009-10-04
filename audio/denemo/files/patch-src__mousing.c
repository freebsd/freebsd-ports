--- src/mousing.c.orig	2009-08-24 03:03:26.000000000 +0900
+++ src/mousing.c	2009-09-28 18:48:47.000000000 +0900
@@ -177,8 +177,11 @@
 		     && pi->measure_number >= si->rightmeasurenum);
     
   pi->the_staff = g_list_nth (si->thescore, pi->staff_number - 1);
-  pi->the_measure
-    = nth_measure_node_in_staff (pi->the_staff, pi->measure_number - 1);
+  if (pi->the_staff != NULL)
+    pi->the_measure
+      = nth_measure_node_in_staff (pi->the_staff, pi->measure_number - 1);
+  else
+    pi->the_measure = NULL;
   if (pi->the_measure != NULL){ /*check to make sure user did not click on empty space*/
 	  obj_iterator = (objnode *) pi->the_measure->data;
 	  pi->cursor_x = 0;
