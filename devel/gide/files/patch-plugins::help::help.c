
$FreeBSD$

--- plugins/help/help.c	2001/07/24 10:39:13	1.1
+++ plugins/help/help.c	2001/07/24 10:40:24
@@ -112,8 +112,8 @@
 		gtk_text_forward_delete(GTK_TEXT(text_widget),
 			gtk_text_get_length(GTK_TEXT(text_widget)));
 		/* FIXME: need to free the font */
-		bold = gdk_font_load(
-			"-misc-fixed-bold-r-normal-*-*-120-*-*-c-*-iso8859-1");
+		bold = gdk_fontset_load(
+			"-misc-fixed-bold-r-normal-*-*-120-*-*-c-*-iso8859-1,*");
 		gtk_text_insert(GTK_TEXT(text_widget), bold,
 			&text_widget->style->black, NULL,
 			_("You need to select a section first") , -1);
@@ -207,10 +207,10 @@
 	g_return_if_fail(GTK_IS_TEXT(text_widget));
 
 	/* FIXME: We should let the user select which font they want */
-	normal = gdk_font_load(
-		"-misc-fixed-medium-r-normal-*-*-120-*-*-c-*-iso8859-1");
-	bold = gdk_font_load(
-		"-misc-fixed-bold-r-normal-*-*-120-*-*-c-*-iso8859-1");
+	normal = gdk_fontset_load(
+		"-misc-fixed-medium-r-normal-*-*-120-*-*-c-*-iso8859-1,*");
+	bold = gdk_fontset_load(
+		"-misc-fixed-bold-r-normal-*-*-120-*-*-c-*-iso8859-1,*");
 
 	fp = popen(cmdstr, "r");
 	g_return_if_fail(fp);
@@ -307,10 +307,10 @@
 	g_return_if_fail(GTK_IS_TEXT(text_widget));
 
 	/* FIXME: We should let the user select which font they want */
-	normal = gdk_font_load(
-		"-misc-fixed-medium-r-normal-*-*-120-*-*-c-*-iso8859-1");
-	bold = gdk_font_load(
-		"-misc-fixed-bold-r-normal-*-*-120-*-*-c-*-iso8859-1");
+	normal = gdk_fontset_load(
+		"-misc-fixed-medium-r-normal-*-*-120-*-*-c-*-iso8859-1,*");
+	bold = gdk_fontset_load(
+		"-misc-fixed-bold-r-normal-*-*-120-*-*-c-*-iso8859-1,*");
 
 	fp = popen(cmdstr, "r");
 	g_return_if_fail(fp);
