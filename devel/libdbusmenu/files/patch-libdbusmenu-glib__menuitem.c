--- ./libdbusmenu-glib/menuitem.c.orig	2012-10-03 15:54:22.000000000 +0000
+++ ./libdbusmenu-glib/menuitem.c	2014-07-03 11:27:19.000000000 +0000
@@ -974,7 +974,7 @@
 		}
 		return mi;
 	}
-	find_id_t find_id = {mi: NULL, id: id};
+	find_id_t find_id = {.mi = NULL, .id = id};
 	find_id_helper(mi, &find_id);
 	return find_id.mi;
 }
@@ -1712,7 +1712,7 @@
 
 	func(mi, data);
 	GList * children = dbusmenu_menuitem_get_children(mi);
-	foreach_struct_t foreach_data = {func: func, data: data};
+	foreach_struct_t foreach_data = {.func = func, .data = data};
 	g_list_foreach(children, foreach_helper, &foreach_data);
 	return;
 }
