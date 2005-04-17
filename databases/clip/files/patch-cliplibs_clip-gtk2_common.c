--- cliplibs/clip-gtk2/common.c.orig	Wed Mar  2 19:50:57 2005
+++ cliplibs/clip-gtk2/common.c	Fri Apr 15 13:17:57 2005
@@ -142,6 +142,8 @@
 _list_remove_cobject(ClipMachine * cm)
 {
         ClipVar *cv;
+        C_object *cobj;
+        C_widget *cwid;
         if (widget_list->t.type != MAP_t)
         	return;
         cv = (ClipVar *)&(widget_list->m.items[0]);
@@ -152,8 +154,8 @@
         		cv = (ClipVar *)&(widget_list->m.items[0]);
 		else
                 	break;
-        	C_object *cobj = (C_object *)((long)(((ClipVar*)&(cv->m.items[0]))->n.d));
-                C_widget *cwid = (C_widget *)((long)(((ClipVar*)&(cv->m.items[0]))->n.d));
+        	cobj = (C_object *)((long)(((ClipVar*)&(cv->m.items[0]))->n.d));
+                cwid = (C_widget *)((long)(((ClipVar*)&(cv->m.items[0]))->n.d));
 
                 if (cobj->objtype)
                 	destroy_c_object(cobj);
