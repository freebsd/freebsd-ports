--- php_mssql.c	2004/12/06 19:45:57	1.137.2.6
+++ php_mssql.c	2004/12/16 21:49:36	1.137.2.7
@@ -1196,10 +1196,8 @@ PHP_FUNCTION(mssql_query)
 	while ((num_fields = dbnumcols(mssql_ptr->link)) <= 0 && retvalue == SUCCEED) {
 		retvalue = dbresults(mssql_ptr->link);
 	}
-	if (retvalue != SUCCEED) {
-		RETURN_FALSE;
-	}
-	if ((num_fields = dbnumcols(mssql_ptr->link)) <= 0) {
+
+	if (num_fields <= 0) {
 		RETURN_TRUE;
 	}

