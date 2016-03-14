--- config.c.orig	1999-01-02 03:14:50 UTC
+++ config.c
@@ -1407,7 +1407,6 @@ free_pagers(pager_t *list)
 		my_free(list->name);
 		my_free(list->text);
 		my_free(list->pagerid);
-		my_free(list->service);
 		free(list);
 	}
 }
