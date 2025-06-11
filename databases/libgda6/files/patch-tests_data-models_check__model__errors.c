../tests/data-models/check_model_errors.c:51:11: error: variable 'ntests' set but not used [-Werror,-Wunused-but-set-variable]
   51 |         guint i, ntests = 0, number_failed = 0;
      |                  ^
1 error generated.

--- tests/data-models/check_model_errors.c.orig	2025-03-02 15:03:58 UTC
+++ tests/data-models/check_model_errors.c
@@ -48,7 +48,7 @@ main (G_GNUC_UNUSED int argc, G_GNUC_UNUSED char **arg
 int
 main (G_GNUC_UNUSED int argc, G_GNUC_UNUSED char **argv)
 {
-	guint i, ntests = 0, number_failed = 0;
+	guint i, number_failed = 0;
 
 	gda_init ();
 	
@@ -58,7 +58,6 @@ main (G_GNUC_UNUSED int argc, G_GNUC_UNUSED char **arg
 		number_failed += n;
 		if (n > 0) 
 			g_print ("Test %d failed\n", i+1);
-		ntests ++;
 	}
 
 	g_print ("TESTS COUNT: %d\n", i);
