--- ./src/Widgets/ListManager.h.orig	Mon Jul 21 18:41:55 2003
+++ ./src/Widgets/ListManager.h	Mon Jul 21 18:43:28 2003
@@ -14,7 +14,8 @@
 
 #include <gtk/gtkwidget.h>
 
-
+using std::multiset;
+using std::string;
 
 
 class ListManager
