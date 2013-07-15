--- src/mousing.c.orig	2011-09-28 05:03:47.000000000 +0200
+++ src/mousing.c	2011-10-01 17:17:17.821965718 +0200
@@ -211,7 +211,11 @@
   pi->nextmeasure = ((si->system_height > 0.5 || x_to_explain > GPOINTER_TO_INT (mwidthiterator->data)) && pi->measure_number >= rightmeasurenum);
 
   pi->the_staff = g_list_nth (si->thescore, pi->staff_number - 1);
-  pi->the_measure = nth_measure_node_in_staff (pi->the_staff, pi->measure_number - 1);
+  if (pi->the_staff != NULL)
+    pi->the_measure
+      = nth_measure_node_in_staff (pi->the_staff, pi->measure_number - 1);
+  else
+    pi->the_measure = NULL;
   if (pi->the_measure != NULL)
     {                           /*check to make sure user did not click on empty space */
       obj_iterator = (objnode *) pi->the_measure->data;
