--- src/cup.c.orig	Thu Dec 22 10:44:34 2005
+++ src/cup.c	Thu Dec 29 21:32:04 2005
@@ -307,6 +307,7 @@
 	    start = ct->start_idx - 1;
 	    end = ct->end_idx - start;
 
+	    {
 	    gint order[end];
 	    for(j=0;j<end;j++)
 		order[j] = j + start;
@@ -340,6 +341,7 @@
 			break;
 		}
 	    }
+	    }
 	}
 
 	if(ct->number_of_teams != -1 &&
@@ -359,6 +361,7 @@
 				  ct->sid, lig(0).teams->len, 
 				  ct->number_of_teams, cup->name);
 
+	    {
 	    gint permutation[lig(0).teams->len];
 	    math_generate_permutation(permutation, 0, lig(0).teams->len - 1);
 
@@ -385,6 +388,7 @@
 				  "cup_load_choose_team (2): not enough teams found in league 0 for chooseteam %s (%d; required: %d) in cup %s (group %d)\n",
 				  ct->sid, number_of_teams, 
 				  ct->number_of_teams, cup->name, cup->group);
+	    }
 	}
 	else
 	{
@@ -475,6 +479,7 @@
 	return;
     }
     
+    {
     gint permutation[teams_local->len];
     for(j=0;j<teams_local->len;j++)
 	permutation[j] = j;
@@ -532,6 +537,7 @@
 	    g_array_remove_index(teams_local, j);
 	
     free_teams_array(&teams_local, FALSE);
+    }
 }
 
 /** Return a pointer array of teams ordered corresponding to
