--- ./src/components/filter/filter_view.vala.orig	2011-06-24 14:40:14.000000000 +0200
+++ ./src/components/filter/filter_view.vala	2011-06-24 14:41:00.000000000 +0200
@@ -370,7 +370,8 @@ namespace Abraca {
 							} else {
 								order = Gtk.SortType.DESCENDING;
 							}
-							sorting = {column.title, order};
+							Sorting tmp = {column.title, order};
+							sorting = tmp;
 							break;
 						}
 					}
