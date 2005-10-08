--- src/cup.c.orig	Sat Sep 10 11:30:49 2005
+++ src/cup.c	Sat Oct  8 00:02:13 2005
@@ -269,6 +269,7 @@
 	    start = ct->start_idx - 1;
 	    end = ct->end_idx - start;
 
+	    {
 	    gint order[end];
 	    for(j=0;j<end;j++)
 		order[j] = j + start;
@@ -301,6 +302,7 @@
 			break;
 		}
 	    }
+	    }
 	}
 
 	if(ct->number_of_teams != -1 &&
@@ -322,6 +324,7 @@
 		main_exit_program(EXIT_CHOOSE_TEAM_ERROR, NULL);
 	    }
 
+	    {
 	    gint permutation[lig(0).teams->len];
 	    math_generate_permutation(permutation, 0, lig(0).teams->len - 1);
 
@@ -349,6 +352,7 @@
 			  ct->sid->str, number_of_teams, ct->number_of_teams, cup->name->str, cup->group);
 		main_exit_program(EXIT_CHOOSE_TEAM_ERROR, NULL);
 	    }
+	    }
 	}
 	else
 	{
@@ -431,6 +435,7 @@
 
     g_array_free(leagues, TRUE);
     
+    {
     gint permutation[teams_local->len];
     for(j=0;j<teams_local->len;j++)
 	permutation[j] = j;
@@ -488,6 +493,7 @@
 	
     free_g_string_array(&sids);
     free_teams_array(&teams_local, FALSE);
+    }
 }
 
 /** Return a pointer array of teams ordered corresponding to
