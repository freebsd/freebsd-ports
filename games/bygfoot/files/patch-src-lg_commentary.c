--- src/lg_commentary.c.orig	Sun Oct 16 11:53:36 2005
+++ src/lg_commentary.c	Tue Nov  1 19:34:50 2005
@@ -49,6 +49,7 @@
     else
 	commentaries = &lg_commentary[unit->event.type];
 
+    {
     gint order[(*commentaries)->len];
     lg_commentary_get_order(*commentaries, order);
 
@@ -87,6 +88,7 @@
 	   i != option_int("string_lg_commentary_token_team_layer0", &lg_tokens) &&
 	   i != option_int("string_lg_commentary_token_team_layer1", &lg_tokens))
 	    free_gchar_ptr(token_rep[i]);
+    }
 }
 
 /** Check whether the commentary conditions are fulfilled and whether
@@ -305,6 +307,7 @@
 	order[i] = -1;
     }
 
+    {
     gint permutation[priority_sum];
 
     math_generate_permutation(permutation, 1, priority_sum);
@@ -325,6 +328,7 @@
 
 		break;
 	    }
+    }
     }
 }
 
