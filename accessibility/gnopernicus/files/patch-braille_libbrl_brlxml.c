--- braille/libbrl/brlxml.c.orig	Tue Aug  3 14:50:31 2004
+++ braille/libbrl/brlxml.c	Tue Aug  3 14:50:48 2004
@@ -730,9 +730,9 @@
 			/* fprintf (stderr, "\n attr_val; %s", *attrs); */
 			if (g_strcasecmp ((gchar*)*attrs, "mode") == 0)
 			{
-			    ++attrs;
 			    gint16 new_offset = 0;
 			    gshort sign = 1;
+			    ++attrs;
 					
 			    attr_val = g_strdup ((gchar*)*attrs);
 			    tattr_val = g_strdup (attr_val);
