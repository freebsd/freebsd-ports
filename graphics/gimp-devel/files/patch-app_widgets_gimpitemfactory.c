--- app/widgets/gimpitemfactory.c.orig	Sat Aug 30 16:19:07 2003
+++ app/widgets/gimpitemfactory.c	Sat Aug 30 18:36:59 2003
@@ -1036,7 +1036,7 @@
 	}
       else
 	{
-	  translation = dgettext (domain, full_path);
+	  translation = g_strdup (dgettext (domain, full_path));
 	}
 
       if (strncmp (item_factory->path, translation,
