--- src/league.c.orig	Sat Sep 10 11:30:49 2005
+++ src/league.c	Sat Oct  8 00:09:34 2005
@@ -423,6 +423,7 @@
     {
 	dest_sids = misc_separate_strings(
 	    g_array_index(elements, PromRelElement, i).dest_sid->str);
+	{
 	gint dest_idcs_int[dest_sids->len];
 	gint dest_idcs_order[dest_sids->len];
 
@@ -447,6 +448,7 @@
 	}
 
 	free_g_string_array(&dest_sids);
+	}
     }
 }
 
