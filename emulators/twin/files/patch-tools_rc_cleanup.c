adding following patch fixes problem

--- ./tools/rc/cleanup.c.orig   Sun Mar 14 13:58:51 1999
+++ ./tools/rc/cleanup.c        Mon Jun 19 07:44:21 2006
@@ -76,7 +76,7 @@
        free_menu_list(node->child);
       str_free(node->data.menuname);
       free_mem(node);
-      node = node->next;
+      node = next;
     }
 }

