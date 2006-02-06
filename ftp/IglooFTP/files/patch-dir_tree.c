--- dir_tree.c.orig	Thu Apr 15 17:05:14 1999
+++ dir_tree.c	Thu Feb  2 02:26:20 2006
@@ -153,7 +153,6 @@
 			      new_ptr[0] = 'B';
 			      gtk_ctree_node_set_row_data_full (ctree, parent, strdup (new_ptr), (GtkDestroyNotify) free);
 			      free (new_ptr);
-			      free (ptr);	// verify that this is a good thing to do       
 
 			      PARENT_BROWSED_FLAG = TRUE;
 			    }
