--- lib/intl.c.orig	Mon Mar 17 14:06:02 2003
+++ lib/intl.c	Mon Mar 17 14:07:10 2003
@@ -65,6 +65,7 @@
     read_aliases ("/usr/share/locale/locale.alias");
     read_aliases ("/usr/local/share/locale/locale.alias");
     read_aliases ("/usr/lib/X11/locale/locale.alias");
+    read_aliases ("/usr/X11R6/lib/X11/locale/locale.alias");
     read_aliases ("/usr/openwin/lib/locale/locale.alias");
   }
   while((p=g_hash_table_lookup(alias_table,lang)) && strcmp(p, lang))
