--- gtkgui/listpack.cpp.orig	Mon Jul 28 20:31:24 2003
+++ gtkgui/listpack.cpp	Mon Jul 28 20:32:17 2003
@@ -49,7 +49,7 @@
 	item->container = container;
 	item->data = data;
 
-	func("list_add:: item %p item->pos = %u
+	func("list_add:: item %p item->pos = %u\
 			item->container= %p item->data=%p", item, item->pos,
 			item->container, item->data);
 	/**list = g_list_append(*list, (void *) item);*/
