--- src/idle-dialog.c.orig	Thu Jul  8 00:17:13 2004
+++ src/idle-dialog.c	Thu Jul  8 00:18:46 2004
@@ -111,12 +111,14 @@
 {
 	char * p;
 	char * ret;
+	int ampcnt = 0;
+	int len;
+	const char *start;
 
 	p = strchr (str, '&');
 	if (!p) return g_strdup (str);
 
 	/* count number of ampersands */
-	int ampcnt = 0;
 	while (p)
 	{
 		ampcnt ++;
@@ -124,12 +126,12 @@
 	}
 	
 	/* make room for the escapes */
-	int len = strlen(str);
+	len = strlen(str);
 	ret = g_new0 (char, len+4*ampcnt+1);
 	
 	/* replace & by &amp; unless its already &amp; */
 	p = strchr (str, '&');
-	const char *start = str;
+	start = str;
 	while (p)
 	{
 		strncat (ret, start, p-start);
@@ -158,6 +160,8 @@
 	char * msg;
 	time_t now = time(0);
 	time_t idle_time;
+	char *ptitle;
+	char *pdesc;
 	
 	/* Set a value for the thingy under the slider */
 	if (3600 > credit)
@@ -201,9 +205,9 @@
 	/* Update the total elapsed time part of the message */
 	idle_time = now - dlg->last_activity;
 	
-	char *ptitle = util_escape_html_markup (
+	ptitle = util_escape_html_markup (
 	                            gtt_project_get_title(dlg->prj));
-	char *pdesc = util_escape_html_markup (
+	pdesc = util_escape_html_markup (
 	                            gtt_project_get_desc(dlg->prj));
 	if (3600 > idle_time)
 	{
