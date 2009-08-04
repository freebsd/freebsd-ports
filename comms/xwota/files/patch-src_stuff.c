--- src/stuff.c.orig	2006-07-28 12:00:10.000000000 -0400
+++ src/stuff.c	2009-08-04 12:03:56.000000000 -0400
@@ -22,6 +22,7 @@
 #include "global.h"
 #include "stuff.h"
 
+void private_messages_log(gchar *date_msg_log,gchar *time_log,gchar *from,gchar *to,gchar *text);
 
 
 int load_preferences()
@@ -330,7 +331,7 @@
 	  GtkTreePath *path;
 	  GtkWidget *spot_list;
 	
-char eor[5];
+char eor[6];
 char *p_eor;	  
 gchar *call,*freq,*country,*state,*grid,*county,*lat,*longitude,*status,*comments,*program,*f1,*f2,*d_ate,*t_ime; 
 char datetime[50],latlong[50],status_comment[30],display_country[50];
