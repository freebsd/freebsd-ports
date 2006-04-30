--- logview/calendar.h.orig	Tue Apr 18 22:20:35 2006
+++ logview/calendar.h	Tue Apr 18 22:20:58 2006
@@ -45,6 +45,7 @@ typedef struct CalendarClass
 	GtkCalendarClass parent_class;
 }CalendarClass;
 
+GType calendar_get_type (void);
 GtkWidget *calendar_new (void);
 void calendar_select_date (Calendar *calendar, GDate *date);
 void calendar_init_data (Calendar *calendar, LogviewWindow *logview);
