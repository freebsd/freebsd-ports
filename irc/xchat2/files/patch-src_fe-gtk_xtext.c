--- src/fe-gtk/xtext.c.orig	Thu Sep 18 07:26:52 2003
+++ src/fe-gtk/xtext.c	Sat Oct 25 22:31:45 2003
@@ -2126,6 +2126,7 @@
 	char *stripped;
 	guchar *new_text;
 	int len;
+	gsize glen;
 
 	stripped = gtk_xtext_selection_get_text (xtext, &len);
 	if (!stripped)
@@ -2158,9 +2159,9 @@
 		}
 		break;
 	default:
-		new_text = g_locale_from_utf8 (stripped, len, NULL, &len, NULL);
+		new_text = g_locale_from_utf8 (stripped, len, NULL, &glen, NULL);
 		gtk_selection_data_set (selection_data_ptr, GDK_SELECTION_TYPE_STRING,
-										8, new_text, len);
+										8, new_text, glen);
 		g_free (new_text);
 	}
 
