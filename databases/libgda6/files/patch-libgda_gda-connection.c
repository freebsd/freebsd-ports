../libgda/gda-connection.c:6931:7: error: variable 'refs' set but not used [-Werror,-Wunused-but-set-variable]
 6931 |         gint refs;
      |              ^
1 error generated.

--- libgda/gda-connection.c.orig	2025-03-02 15:03:58 UTC
+++ libgda/gda-connection.c
@@ -6928,14 +6928,12 @@ gda_connection_prepare_operation_create_table_v (GdaCo
 	gchar   *arg;
 	GType    type;
 	GdaServerOperationCreateTableFlag flag;
-	gint refs;
 	GList *arguments = NULL;
 	GdaServerOperationCreateTableArg* argument;
 
 	va_start (args, error);
 	type = 0;
 	arg = NULL;
-	refs = -1;
 
 	while ((arg = va_arg (args, gchar*))) {
 		argument = gda_server_operation_create_table_arg_new ();
@@ -6956,7 +6954,6 @@ gda_connection_prepare_operation_create_table_v (GdaCo
 			gchar *fkey_ondelete;
 			gchar *fkey_onupdate;
 
-			refs++;
 			GList *lfields = NULL;
 
 			fkey_table = va_arg (args, gchar*);
