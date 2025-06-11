../tests/data-models/check_pmodel.c:108:11: error: variable 'ntests' set but not used [-Werror,-Wunused-but-set-variable]
  108 |         guint i, ntests = 0, number_failed = 0;
      |                  ^
1 error generated.

--- tests/data-models/check_pmodel.c.orig	2025-03-02 15:03:58 UTC
+++ tests/data-models/check_pmodel.c
@@ -105,7 +105,7 @@ main (G_GNUC_UNUSED int argc, G_GNUC_UNUSED char **arg
 int
 main (G_GNUC_UNUSED int argc, G_GNUC_UNUSED char **argv)
 {
-	guint i, ntests = 0, number_failed = 0;
+	guint i, number_failed = 0;
 	GdaConnection *cnc;
 
 	gda_init ();
@@ -119,7 +119,6 @@ main (G_GNUC_UNUSED int argc, G_GNUC_UNUSED char **arg
 		number_failed += n;
 		if (n > 0) 
 			g_print ("Test %d failed\n", i+1);
-		ntests ++;
 	}
 
 	g_object_unref (cnc);
