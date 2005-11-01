--- src/league.c.orig	Sun Oct 16 11:53:36 2005
+++ src/league.c	Tue Nov  1 20:26:35 2005
@@ -457,6 +457,7 @@
     {
 	dest_sids = misc_separate_strings(
 	    g_array_index(elements, PromRelElement, i).dest_sid);
+	{
 	gint dest_idcs_int[dest_sids->len];
 	gint dest_idcs_order[dest_sids->len];
 
@@ -481,6 +482,7 @@
 	}
 
 	free_gchar_array(&dest_sids);
+	}
     }
 }
 
