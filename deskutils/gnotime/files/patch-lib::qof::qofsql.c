--- lib/qof/qofsql.c.orig	Sun May 23 16:58:28 2004
+++ lib/qof/qofsql.c	Thu Jul  8 00:11:24 2004
@@ -133,8 +133,9 @@
 	if (('\'' == str[0]) ||
 	    ('\"' == str[0]))
 	{
+		size_t len;
 		str ++;
-		size_t len = strlen(str);
+		len = strlen(str);
 		str[len-1] = 0;
 	}
 	return str;
@@ -146,6 +147,15 @@
 	char tmpbuff[128];
 	GSList *param_list;
 	QofQueryPredData *pred_data = NULL;
+	sql_field_item * sparam;
+	char * qparam_name;
+	sql_field_item * svalue;
+	char * qvalue_name;
+	QofQueryCompare qop;
+	char *table_name;
+	char *param_name;
+	QofType param_type;
+	QofQuery *qq;
 	
 	if (NULL == cond)
 	{
@@ -161,14 +171,14 @@
 		PWARN("missing left paramter");
 		return NULL;
 	}
-	sql_field_item * sparam = cond->d.pair.left->item;
+	sparam = cond->d.pair.left->item;
 	if (SQL_name != sparam->type)
 	{
 		PWARN("we support only paramter names at this time (parsed %d)",
           sparam->type);
 		return NULL;
 	}
-	char * qparam_name = sparam->d.name->data;
+	qparam_name = sparam->d.name->data;
 	if (NULL == qparam_name)
 	{
 		PWARN ("missing paramter name");
@@ -183,13 +193,13 @@
 		PWARN ("missing right paramter");
 		return NULL;
 	}
-	sql_field_item * svalue = cond->d.pair.right->item;
+	svalue = cond->d.pair.right->item;
 	if (SQL_name != svalue->type)
 	{
 		PWARN("we support only simple values (parsed as %d)", svalue->type);
 		return NULL;
 	}
-	char * qvalue_name = svalue->d.name->data;
+	qvalue_name = svalue->d.name->data;
 	if (NULL == qvalue_name)
 	{
 		PWARN("missing value");
@@ -202,16 +212,18 @@
 	 * If it is, look up the value. */
 	if (0 == strncasecmp (qvalue_name, "kvp://", 6))
 	{
+		KvpValue *kv;
+		KvpValueType kvt;
 		if (NULL == query->kvp_join)
 		{
 			PWARN ("missing kvp frame");
 			return NULL;
 		}
-		KvpValue *kv = kvp_frame_get_value (query->kvp_join, qvalue_name+5);
+		kv = kvp_frame_get_value (query->kvp_join, qvalue_name+5);
 		/* If there's no value, its not an error; 
 		 * we just don't do this predicate */
 		if (!kv) return NULL;  
-		KvpValueType kvt = kvp_value_get_type (kv);
+		kvt = kvp_value_get_type (kv);
 
 		tmpbuff[0] = 0x0;
 		qvalue_name = tmpbuff;
@@ -251,7 +263,6 @@
 	param_list = qof_query_build_param_list (qparam_name, NULL);
 
 	/* Get the where-term comparison operator */
-	QofQueryCompare qop;
 	switch (cond->op)
 	{
 		case SQL_eq:    qop = QOF_COMPARE_EQUAL; break;
@@ -270,8 +281,6 @@
 	/* OK, need to know the type of the thing being matched 
 	 * in order to build the correct predicate.  Get the type 
 	 * from the object parameters. */
-	char *table_name;
-	char *param_name;
 	get_table_and_param (qparam_name, &table_name, &param_name);
 	if (NULL == table_name)
 	{
@@ -290,7 +299,7 @@
 		return NULL;
 	}
 
-	QofType param_type = qof_class_get_parameter_type (table_name, param_name);
+	param_type = qof_class_get_parameter_type (table_name, param_name);
 	if (!param_type) 
 	{
 		PWARN ("The parameter \'%s\' on object \'%s\' is not known", 
@@ -319,7 +328,7 @@
 	}
 	else if (!strcmp (param_type, QOF_TYPE_INT64))
 	{
-		gint64 ival = atoll (qvalue_name);
+		gint64 ival = strtoll (qvalue_name, (char **)NULL, 10);
 		pred_data = qof_query_int64_predicate (qop, ival);
 	}
 	else if (!strcmp (param_type, QOF_TYPE_DOUBLE))
@@ -337,16 +346,17 @@
 		// XXX FIXME: this doesn't handle time strings, only date strings
 		// XXX should also see if we need to do a day-compare or time-compare.
 		/* work around highly bogus locale setting */
+		time_t exact;
+		int rc;
+		Timespec ts;
 		qof_date_format_set(QOF_DATE_FORMAT_US);
 
-		time_t exact;
-		int rc = qof_scan_date_secs (qvalue_name, &exact);
+		rc = qof_scan_date_secs (qvalue_name, &exact);
 		if (0 == rc) 
 		{
 			PWARN ("unable to parse date: %s", qvalue_name);
 			return NULL;
 		}
-		Timespec ts;
 		ts.tv_sec = exact;
 		ts.tv_nsec = 0;
 		pred_data = qof_query_date_predicate (qop, QOF_DATE_MATCH_DAY, ts);
@@ -367,7 +377,9 @@
 	else if (!strcmp (param_type, QOF_TYPE_GUID))
 	{
 		GUID guid;
+		QofGuidMatch gm;
 		gboolean rc = string_to_guid (qvalue_name, &guid);
+		GList *guid_list;
 		if (0 == rc)
 		{
 			PWARN ("unable to parse guid: %s", qvalue_name);
@@ -377,9 +389,9 @@
 		// XXX less, than greater than don't make sense,
 		// should check for those bad conditions
 
-		QofGuidMatch gm = QOF_GUID_MATCH_ANY;
+		gm = QOF_GUID_MATCH_ANY;
 		if (QOF_COMPARE_NEQ == qop) gm = QOF_GUID_MATCH_NONE;
-		GList *guid_list = g_list_append (NULL, &guid);
+		guid_list = g_list_append (NULL, &guid);
 		pred_data = qof_query_guid_predicate (gm, guid_list);
 
 		g_list_free (guid_list);
@@ -390,11 +402,15 @@
 		 * /some/path/string:value
 		 */
 		char *sep = strchr (qvalue_name, ':');
+		char * path;
+		char * str;
+		char * p;
+		KvpValue *kval = NULL;
+		int len;
 		if (!sep) return NULL;
 		*sep = 0;
-		char * path = qvalue_name;
-		char * str = sep +1;
-		char * p;
+		path = qvalue_name;
+		str = sep +1;
 		/* If str has only digits, we know its a plain number.
 		 * If its numbers and a decimal point, assume a float
 		 * If its numbers and a slash, assume numeric
@@ -402,8 +418,7 @@
 		 * If it looks like an iso date ... 
 		 * else assume its a string.
 		 */
-		KvpValue *kval = NULL;
-		int len = strlen (str);
+		len = strlen (str);
 		if ((32 == len) && (32 == strspn (str, "0123456789abcdef")))
 		{
 			GUID guid;
@@ -413,7 +428,7 @@
 		else
 		if (len == strspn (str, "0123456789"))
 		{
-			kval = kvp_value_new_gint64 (atoll(str));
+			kval = kvp_value_new_gint64 (strtoll(str, (char **)NULL, 10));
 		}
 		else
 		if ((p=strchr (str, '.')) && 
@@ -455,7 +470,7 @@
 		return NULL;
 	}
 
-	QofQuery *qq = qof_query_create();
+	qq = qof_query_create();
 	qof_query_add_term (qq, param_list, pred_data, QOF_QUERY_FIRST_TERM);
 	return qq;
 }
@@ -471,9 +486,10 @@
 		{
 			QofQuery *qleft = handle_where (query, swear->d.pair.left);
 			QofQuery *qright = handle_where (query, swear->d.pair.right);
+			QofQueryOp qop;
+			QofQuery * qq;
 			if (NULL == qleft) return qright;
 			if (NULL == qright) return qleft;
-			QofQueryOp qop;
 			switch (swear->d.pair.op)
 			{
 				case SQL_and: qop = QOF_QUERY_AND; break;
@@ -484,7 +500,7 @@
 					qof_query_destroy (qright);
 					return NULL;
 			}
-			QofQuery * qq = qof_query_merge (qleft, qright, qop);
+			qq = qof_query_merge (qleft, qright, qop);
 			qof_query_destroy (qleft);
 			qof_query_destroy (qright);
 			return qq;
@@ -511,11 +527,11 @@
 static void 
 handle_sort_order (QofSqlQuery *query, GList *sorder_list)
 {
-	if (!sorder_list) return;
-
 	GSList *qsp[3];
 	gboolean direction[3];
 	int i;
+	if (!sorder_list) return;
+
 
 	for (i=0; i<3; i++)
 	{
@@ -524,14 +540,15 @@
 
 		if (sorder_list)
 		{
+			char * qparam_name = NULL;
+			GList *n;
 			sql_order_field *sorder = sorder_list->data;
 
 			/* Set the sort direction */
 			if (SQL_asc == sorder->order_type) direction[i] = TRUE;
 
 			/* Find the paramter name */
-			char * qparam_name = NULL;
-			GList *n = sorder->name;
+			n = sorder->name;
 			if (n)
 			{
 				qparam_name = n->data;
@@ -559,6 +576,9 @@
 void 
 qof_sql_query_parse (QofSqlQuery *query, const char *str)
 {
+	GList *tables;
+	sql_select_statement *sss;
+	sql_where * swear;
 	if (!query) return;
 
 	/* Delete old query, if any */
@@ -590,14 +610,14 @@
 	 * user wrote "SELECT * FROM tableA, tableB WHERE ..."
 	 * then we don't have a single unique table-name.
 	 */
-	GList *tables = sql_statement_get_tables (query->parse_result);
+	tables = sql_statement_get_tables (query->parse_result);
 	if (1 == g_list_length (tables))
 	{
 		query->single_global_tablename = tables->data;
 	}
 
-	sql_select_statement *sss = query->parse_result->statement;
-	sql_where * swear = sss->where;
+	sss = query->parse_result->statement;
+	swear = sss->where;
 	if (swear)
 	{
 		/* Walk over the where terms, turn them into QOF predicates */
@@ -626,6 +646,7 @@
 qof_sql_query_run (QofSqlQuery *query, const char *str)
 {
 	GList *node;
+	GList *results;
 
 	if (!query) return NULL;
 
@@ -635,7 +656,7 @@
 	qof_query_set_book (query->qof_query, query->book);
 
 	// qof_query_print (query->qof_query);
-	GList *results = qof_query_run (query->qof_query);
+	results = qof_query_run (query->qof_query);
 
 	return results;
 }
@@ -644,6 +665,7 @@
 qof_sql_query_rerun (QofSqlQuery *query)
 {
 	GList *node;
+	GList *results;
 
 	if (!query) return NULL;
 
@@ -652,7 +674,7 @@
 	qof_query_set_book (query->qof_query, query->book);
 
 	// qof_query_print (query->qof_query);
-	GList *results = qof_query_run (query->qof_query);
+	results = qof_query_run (query->qof_query);
 
 	return results;
 }
