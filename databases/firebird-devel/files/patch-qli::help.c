--- qli/help.c.orig	Tue Nov 12 16:03:39 2002
+++ qli/help.c	Tue Nov 12 17:00:35 2002
@@ -289,7 +289,7 @@
 		  isc_25.isc_26))
 	continue;
     if (++topics == 1 && banner)
-	ib_printf ("%s\n", banner, string, parent);
+	ib_printf ("%s%s%s\n", banner, string, parent);
     p = line + ((ptr - line + COLUMN_WIDTH - 1) / COLUMN_WIDTH) * COLUMN_WIDTH;
     if (p + l > line + RIGHT_MARGIN)
 	{
