--- Robot/dnd.c.orig	Wed May 30 21:56:42 2007
+++ Robot/dnd.c	Wed May 30 21:57:06 2007
@@ -80,7 +80,8 @@
 			PANEL_DROP_FULL,	TRUE,
 			NULL); 
 }
- 
+
+static void             get_primary_selection();
  
 /* drop_proc: Setup the drag operation and handle the drop.
  *
@@ -93,7 +94,6 @@
 Event		*event;
 {
 	Selection_requestor	sel_req;
-        static void             get_primary_selection();
 
 	sel_req = xv_get(item, PANEL_DROP_SEL_REQ);
         
