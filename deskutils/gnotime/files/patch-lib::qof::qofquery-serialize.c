--- lib/qof/qofquery-serialize.c.orig	Wed Jul  7 23:54:57 2004
+++ lib/qof/qofquery-serialize.c	Thu Jul  8 00:02:12 2004
@@ -228,9 +228,10 @@
 	if (!safe_strcmp (pd->type_name, QOF_TYPE_STRING))
 	{
 		xmlNodePtr topnode = xmlNewNode (NULL, "qofquery:pred-string");
+		query_string_t pdata;
 		PUT_HOW ("qofquery:compare", pd->how, LT, LTE, EQUAL, GT, GTE, NEQ);
 
-		query_string_t pdata = (query_string_t) pd;
+		pdata = (query_string_t) pd;
 		PUT_MATCH2("qofquery:string-match", pdata->options,
                        STRING_MATCH, NORMAL, CASEINSENSITIVE);
 		PUT_BOOL ("qofquery:is-regex", pdata->is_regex);
@@ -240,9 +241,10 @@
 	if (!safe_strcmp (pd->type_name, QOF_TYPE_NUMERIC))
 	{
 		xmlNodePtr topnode = xmlNewNode (NULL, "qofquery:pred-numeric");
+		query_numeric_t pdata;
 		PUT_HOW ("qofquery:compare", pd->how, LT, LTE, EQUAL, GT, GTE, NEQ);
 
-		query_numeric_t pdata = (query_numeric_t) pd;
+		pdata = (query_numeric_t) pd;
 		PUT_MATCH3("qofquery:numeric-match", pdata->options,
 		                 NUMERIC_MATCH, DEBIT, CREDIT, ANY);
 		
@@ -252,11 +254,12 @@
 	if (!safe_strcmp (pd->type_name, QOF_TYPE_KVP))
 	{
 		xmlNodePtr topnode = xmlNewNode (NULL, "qofquery:pred-kvp");
+		query_kvp_t pdata;
+		GSList *n;
 		PUT_HOW ("qofquery:compare", pd->how, LT, LTE, EQUAL, GT, GTE, NEQ);
 
-		query_kvp_t pdata = (query_kvp_t) pd;
+		pdata = (query_kvp_t) pd;
 		
-		GSList *n;
 		for (n=pdata->path; n; n=n->next)
 		{
 			PUT_STR ("qofquery:kvp-path", n->data);
@@ -267,9 +270,10 @@
 	if (!safe_strcmp (pd->type_name, QOF_TYPE_DATE))
 	{
 		xmlNodePtr topnode = xmlNewNode (NULL, "qofquery:pred-date");
+		query_date_t pdata;
 		PUT_HOW ("qofquery:compare", pd->how, LT, LTE, EQUAL, GT, GTE, NEQ);
 
-		query_date_t pdata = (query_date_t) pd;
+		pdata = (query_date_t) pd;
 		
 		PUT_MATCH2("qofquery:date-match", pdata->options,
 		                 DATE_MATCH, NORMAL, ROUNDED);
@@ -280,18 +284,20 @@
 	if (!safe_strcmp (pd->type_name, QOF_TYPE_INT64))
 	{
 		xmlNodePtr topnode = xmlNewNode (NULL, "qofquery:pred-int64");
+		query_int64_t pdata;
 		PUT_HOW ("qofquery:compare", pd->how, LT, LTE, EQUAL, GT, GTE, NEQ);
 
-		query_int64_t pdata = (query_int64_t) pd;
+		pdata = (query_int64_t) pd;
 		PUT_INT64 ("qofquery:int64", pdata->val);
 		return topnode;
 	}
 	if (!safe_strcmp (pd->type_name, QOF_TYPE_INT32))
 	{
 		xmlNodePtr topnode = xmlNewNode (NULL, "qofquery:pred-int32");
+		query_int32_t pdata;
 		PUT_HOW ("qofquery:compare", pd->how, LT, LTE, EQUAL, GT, GTE, NEQ);
 
-		query_int32_t pdata = (query_int32_t) pd;
+		pdata = (query_int32_t) pd;
 		
 		PUT_INT32 ("qofquery:int32", pdata->val);
 		return topnode;
@@ -299,9 +305,10 @@
 	if (!safe_strcmp (pd->type_name, QOF_TYPE_DOUBLE))
 	{
 		xmlNodePtr topnode = xmlNewNode (NULL, "qofquery:pred-double");
+		query_double_t pdata;
 		PUT_HOW ("qofquery:compare", pd->how, LT, LTE, EQUAL, GT, GTE, NEQ);
 
-		query_double_t pdata = (query_double_t) pd;
+		pdata = (query_double_t) pd;
 		
 		PUT_DBL ("qofquery:double", pdata->val);
 		return topnode;
@@ -309,9 +316,10 @@
 	if (!safe_strcmp (pd->type_name, QOF_TYPE_BOOLEAN))
 	{
 		xmlNodePtr topnode = xmlNewNode (NULL, "qofquery:pred-boolean");
+		query_boolean_t pdata;
 		PUT_HOW ("qofquery:compare", pd->how, LT, LTE, EQUAL, GT, GTE, NEQ);
 
-		query_boolean_t pdata = (query_boolean_t) pd;
+		pdata = (query_boolean_t) pd;
 		
 		PUT_BOOL ("qofquery:boolean", pdata->val);
 		return topnode;
@@ -386,9 +394,10 @@
 	for ( ; n; n=n->next)
 	{
 		QofQueryTerm *qt = n->data;
+		xmlNodePtr t;
 		if (!qt) continue;
 
-		xmlNodePtr t = qof_query_one_term_to_xml (n->data);
+		t = qof_query_one_term_to_xml (n->data);
 		if (t) xmlAddChild (terms, t);
 	}
 	return terms;
@@ -419,31 +428,37 @@
 qof_query_sorts_to_xml (QofQuery *q)
 {
 	QofQuerySort *s[3];
+	xmlNodePtr sortlist;
+	int i;
 	qof_query_get_sorts (q, &s[0], &s[1], &s[2]);
 
 	if (NULL == s[0]) return NULL;
 
-	xmlNodePtr sortlist = xmlNewNode (NULL, "qofquery:sort-list");
-	int i;
+	sortlist = xmlNewNode (NULL, "qofquery:sort-list");
 	for (i=0; i<3; i++)
 	{
+		GSList *plist;
+		xmlNodePtr sort;
+		xmlNodePtr topnode;
+		gboolean increasing;
+		gint opt;
+		xmlNodePtr pl;
 		if (NULL == s[i]) continue;
 
-		GSList *plist = qof_query_sort_get_param_path (s[i]);
+		plist = qof_query_sort_get_param_path (s[i]);
 		if (!plist) continue;
 
-		xmlNodePtr sort = xmlNewNode (NULL, "qofquery:sort");
+		sort = xmlNewNode (NULL, "qofquery:sort");
 		xmlAddChild (sortlist, sort);
 
-		xmlNodePtr topnode = sort;
-
-		gboolean increasing = qof_query_sort_get_increasing (s[i]);
+		topnode = sort;
+		increasing = qof_query_sort_get_increasing (s[i]);
 		PUT_STR ("qofquery:order", increasing ? "DESCENDING" : "ASCENDING");
 
-		gint opt = qof_query_sort_get_sort_options (s[i]);
+		opt = qof_query_sort_get_sort_options (s[i]);
 		PUT_INT32 ("qofquery:options", opt);
 
-		xmlNodePtr pl = qof_query_param_path_to_xml (plist);
+		pl = qof_query_param_path_to_xml (plist);
 		if (pl) xmlAddChild (sort, pl);
 	}
 
@@ -456,15 +471,18 @@
 do_qof_query_to_xml (QofQuery *q, xmlNodePtr topnode)
 {
 	QofIdType search_for = qof_query_get_search_for (q);
+	xmlNodePtr terms;
+	xmlNodePtr sorts;
+	gint max_results;
 	PUT_STR ("qofquery:search-for", search_for);
 
-	xmlNodePtr terms = qof_query_terms_to_xml(q);
+	terms = qof_query_terms_to_xml(q);
 	if (terms) xmlAddChild (topnode, terms);
 
-	xmlNodePtr sorts = qof_query_sorts_to_xml (q);
+	sorts = qof_query_sorts_to_xml (q);
 	if (sorts) xmlAddChild (topnode, sorts);
 
-	gint max_results = qof_query_get_max_results (q);
+	max_results = qof_query_get_max_results (q);
 	PUT_INT32 ("qofquery:max-results", max_results);
 }
 
