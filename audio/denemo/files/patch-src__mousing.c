--- src/mousing.c.orig	2011-04-27 19:59:45.127257000 +0200
+++ src/mousing.c	2011-05-07 10:52:03.000000000 +0200
@@ -202,8 +202,11 @@
 		     && pi->measure_number >= rightmeasurenum);
     
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
