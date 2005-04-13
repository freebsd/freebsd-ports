--- pkg.c.orig	Wed Apr 13 16:04:58 2005
+++ pkg.c	Wed Apr 13 16:05:33 2005
@@ -1024,7 +1024,7 @@
     tmp = pkgs;
     while (tmp != NULL)
     {
-      dups_list = g_slist_concat (dups_list, get_l_libs(tmp->data));
+      dups_list = g_slist_concat (dups_list, g_slist_copy(get_l_libs(tmp->data)));
       tmp = tmp->next;
     }
 
@@ -1067,7 +1067,7 @@
     tmp = pkgs;
     while (tmp != NULL)
     {
-      dups_list = g_slist_concat (dups_list, get_L_libs(tmp->data));
+      dups_list = g_slist_concat (dups_list, g_slist_copy(get_L_libs(tmp->data)));
       tmp = tmp->next;
     }
 
