--- src/lg_commentary.c.orig	Thu Dec 22 10:44:34 2005
+++ src/lg_commentary.c	Thu Dec 29 21:25:43 2005
@@ -210,6 +210,7 @@
 	order[i] = -1;
     }
 
+    {
     gint permutation[priority_sum];
 
     math_generate_permutation(permutation, 1, priority_sum);
@@ -230,6 +231,7 @@
 
 		break;
 	    }
+    }
     }
 }
 
