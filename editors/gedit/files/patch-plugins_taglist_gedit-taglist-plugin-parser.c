--- plugins/taglist/gedit-taglist-plugin-parser.c.orig	Wed Jan 26 19:28:35 2005
+++ plugins/taglist/gedit-taglist-plugin-parser.c	Wed Jan 26 19:28:58 2005
@@ -276,12 +276,13 @@
 		else
 		{
 			const char * const *langs_pointer;
+			gchar* lang;
 			gint i;
+			gint cur_lanking = 1;
 
 			langs_pointer = g_get_language_names ();
 
-			gchar* lang= (gchar*)xmlGetProp (cur, (const xmlChar*) "lang");
-			gint cur_lanking = 1;
+			lang= (gchar*)xmlGetProp (cur, (const xmlChar*) "lang");
 
 			/* 
 			 * When found a new TagGroup, append the best 
