--- src/lg_commentary.c.orig	Sat Sep 10 11:30:49 2005
+++ src/lg_commentary.c	Sat Oct  8 00:06:21 2005
@@ -48,6 +48,7 @@
     else
 	commentaries = &lg_commentary[unit->event.type];
 
+    {
     gint order[(*commentaries)->len];
     lg_commentary_get_order(*commentaries, order);
 
@@ -89,6 +90,7 @@
 	    g_free(token_rep[i]);
 	    token_rep[i] = NULL;
 	}
+    }
 }
 
 /** Check whether the commentary conditions are fulfilled and whether
@@ -310,6 +312,7 @@
 	order[i] = -1;
     }
 
+    {
     gint permutation[priority_sum];
 
     math_generate_permutation(permutation, 1, priority_sum);
@@ -330,6 +333,7 @@
 
 		break;
 	    }
+    }
     }
 }
 
