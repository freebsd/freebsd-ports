--- config.c.orig	Fri Jan  1 22:14:50 1999
+++ config.c	Wed May  4 16:28:49 2005
@@ -1407,7 +1407,6 @@
 		my_free(list->name);
 		my_free(list->text);
 		my_free(list->pagerid);
-		my_free(list->service);
 		free(list);
 	}
 }


