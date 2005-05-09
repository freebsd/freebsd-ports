--- src/misc.c.orig	Sun May  8 16:05:33 2005
+++ src/misc.c	Sun May  8 16:06:48 2005
@@ -145,6 +145,7 @@
     GtkTextIter iter;
     guchar* p;
     guchar* text=g_strdup(str);
+    gchar out[7]; /* max utf-8 length plus \0 */ 
 
                 
     /* is the scroll bar at the bottom ?? */
@@ -201,7 +202,6 @@
         {
           tmp=g_utf8_get_char(p); /* It's not a color code, so get the entire char. */
           /* gchar *out = g_locale_to_utf8 (&text[i], 1, NULL, NULL, NULL);  */
-          gchar out[7]; /* max utf-8 length plus \0 */
           out[g_unichar_to_utf8(tmp,out)]='\0'; /* convert and terminate */
           g_assert(g_utf8_validate(out,-1,NULL));
           
