--- php_mssql.c	2004/12/14 17:22:10	1.86.2.41
+++ php_mssql.c	2004/12/16 21:48:17	1.86.2.42
@@ -1206,10 +1206,8 @@ PHP_FUNCTION(mssql_query)
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

