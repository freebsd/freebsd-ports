--- src/debugger.c.orig	Fri Jan 30 20:24:26 2004
+++ src/debugger.c	Fri Jan 30 20:29:07 2004
@@ -2092,9 +2092,11 @@
 void debugger_query_evaluate_expr_tip (const gchar *expr,
 			void (*parser) (GList *outputs, gpointer data), gpointer data)
 {
+	gchar *printcmd;
+
 	query_set_verbose (FALSE);
 	query_set_print_staticmembers (FALSE);
-	gchar *printcmd = g_strconcat ("print ", expr, NULL);
+	printcmd = g_strconcat ("print ", expr, NULL);
 	debugger_put_cmd_in_queqe (printcmd, DB_CMD_NONE, parser, data);
 	query_set_verbose (TRUE);
 	query_set_print_staticmembers (TRUE);
@@ -2104,9 +2106,11 @@
 void debugger_query_evaluate_expr (const gchar *expr,
 			void (*parser) (GList *outputs, gpointer data), gpointer data)
 {
+	gchar *printcmd;
+
 	query_set_print_pretty (TRUE);
 	query_set_verbose (FALSE);
-	gchar *printcmd = g_strconcat ("print ", expr, NULL);
+	printcmd = g_strconcat ("print ", expr, NULL);
 	debugger_put_cmd_in_queqe (printcmd, DB_CMD_SE_MESG | DB_CMD_SE_DIALOG,
 				parser, data);
 	query_set_print_pretty (FALSE);
