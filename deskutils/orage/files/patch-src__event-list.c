--- ./src/event-list.c.orig	2013-02-01 10:11:19.000000000 +0000
+++ ./src/event-list.c	2013-02-01 17:22:20.000000000 +0000
@@ -373,9 +373,10 @@
     guint           len = 50;
 
     stime = format_time(el, appt, par);
-    if (appt->alarmtime != 0)
-        if (appt->sound != NULL)
-            flags[0] = 'S';
+    if (appt->display_alarm_orage || appt->display_alarm_notify 
+    ||  appt->sound_alarm || appt->procedure_alarm)
+        if (appt->alarm_persistent)
+            flags[0] = 'P';
         else
             flags[0] = 'A';
     else
@@ -391,8 +392,10 @@
         flags[1] = 'M';
     else if (appt->freq == XFICAL_FREQ_YEARLY)
         flags[1] = 'Y';
+    else if (appt->freq == XFICAL_FREQ_HOURLY)
+        flags[1] = 'H';
     else
-        flags[1] = 'n';
+        flags[1] = '?';
 
     if (appt->availability != 0)
         flags[2] = 'B';
@@ -1320,7 +1323,7 @@
     gtk_tree_view_append_column(GTK_TREE_VIEW(el->TreeView), col);
     gtk_tree_view_column_set_visible(col, FALSE);
 
-    gtk_tooltips_set_tip(el->Tooltips, el->TreeView, _("Double click line to edit it.\n\nFlags in order:\n\t 1. Alarm: n=no alarm\n\t\t A=visual Alarm S=also Sound alarm\n\t 2. Recurrence: n=no recurrence\n\t\t D=Daily W=Weekly M=Monthly Y=Yearly\n\t 3. Type: f=free B=Busy\n\t 4. Located in file:\n\t\tO=Orage A=Archive F=Foreign\n\t 5. Appointment type:\n\t\tE=Event T=Todo J=Journal"), NULL);
+    gtk_tooltips_set_tip(el->Tooltips, el->TreeView, _("Double click line to edit it.\n\nFlags in order:\n\t 1. Alarm: n=no alarm\n\t\t A=Alarm is set P=Persistent alarm is set\n\t 2. Recurrence: n=no recurrence\n\t\t H=Hourly D=Daily W=Weekly M=Monthly Y=Yearly\n\t 3. Type: f=free B=Busy\n\t 4. Located in file:\n\t\tO=Orage A=Archive F=Foreign\n\t 5. Appointment type:\n\t\tE=Event T=Todo J=Journal"), NULL);
 
     g_signal_connect(el->TreeView, "row-activated",
             G_CALLBACK(editEvent), el);
