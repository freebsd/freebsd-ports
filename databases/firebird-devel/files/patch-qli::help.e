--- qli/help.e.orig	Fri Aug  4 06:53:52 2000
+++ qli/help.e	Mon Nov 18 19:22:44 2002
@@ -160,7 +160,7 @@
     if (!(l = p - X.TOPIC))
 	continue;
     if (++topics == 1 && banner)
-	ib_printf ("%s\n", banner, string, parent);
+	ib_printf ("%s%s%s\n", banner, string, parent);
     p = line + ((ptr - line + COLUMN_WIDTH - 1) / COLUMN_WIDTH) * COLUMN_WIDTH;
     if (p + l > line + RIGHT_MARGIN)
 	{
