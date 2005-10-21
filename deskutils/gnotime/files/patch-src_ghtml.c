--- src/ghtml.c.orig	Fri Oct 21 06:52:04 2005
+++ src/ghtml.c	Fri Oct 21 06:53:15 2005
@@ -1191,6 +1191,7 @@
 get_ivl_start_stop_common_str_scm (GttGhtml *ghtml, GttInterval *ivl,
 					 time_t starp, gboolean prt_date)
 {
+	GString *str;
 	char buff[100];
 
 	if (prt_date) {
@@ -1199,7 +1200,6 @@
 		qof_print_time_buff (buff, 100, starp);
 	}
 
-	GString *str;
 	str = g_string_new (NULL);
 
 	if (ghtml->show_links)
