--- lib/qof/qofquery-deserial.c.orig	Sun May 23 16:57:30 2004
+++ lib/qof/qofquery-deserial.c	Wed Jul  7 23:54:09 2004
@@ -80,7 +80,7 @@
    if (0 == strcmp (TOK, node->name))                        \
    {                                                         \
       const char *str = GET_TEXT (node);                     \
-      gint64 ival = atoll (str);                             \
+      gint64 ival = strtoll (str, (char **)NULL, 10);                             \
       FN (SELF, ival);                                       \
    }                                                         \
    else
@@ -182,10 +182,11 @@
 static QofQueryPredData *                                       \
 SUBRNAME (xmlNodePtr root)                                      \
 {                                                               \
+	QofQueryCompare how = QOF_COMPARE_EQUAL;                     \
+	QofQueryPredData *pred;                                      \
 	xmlNodePtr xp = root->xmlChildrenNode;                       \
 	xmlNodePtr node;                                             \
                                                                 \
-	QofQueryCompare how = QOF_COMPARE_EQUAL;                     \
 	CTYPE val = 0;                                               \
                                                                 \
 	for (node=xp; node; node = node->next)                       \
@@ -197,7 +198,6 @@
 		{}                                                        \
 	}                                                            \
                                                                 \
-	QofQueryPredData *pred;                                      \
 	pred = PRED (how, val);                                      \
 	return pred;                                                 \
 }
@@ -245,10 +245,11 @@
 static QofQueryPredData *
 qof_query_pred_kvp_from_xml (xmlNodePtr root)
 {
+	QofQueryCompare how = QOF_COMPARE_EQUAL;
+	QofQueryPredData *pred;
 	xmlNodePtr xp = root->xmlChildrenNode;
 	xmlNodePtr node;
 
-	QofQueryCompare how = QOF_COMPARE_EQUAL;
 	GSList *path = NULL;
 	KvpValue *value = NULL;
 
@@ -271,7 +272,6 @@
 		GET_DATE(&value,    wrap_new_timespec, "qofquery:date");
 	}
 
-	QofQueryPredData *pred;
 	pred = qof_query_kvp_predicate (how, path, value);
 	g_slist_free (path);
 	return pred;
@@ -282,9 +282,11 @@
 static QofQueryPredData *
 qof_query_pred_guid_from_xml (xmlNodePtr root)
 {
+	QofQueryPredData *pred;
+   GList *guid_list = NULL;
+   GList *n;
 	xmlNodePtr xp = root->xmlChildrenNode;
 	xmlNodePtr node;
-   GList *guid_list = NULL;
 
 	QofGuidMatch sm = QOF_GUID_MATCH_ANY;
 
@@ -313,11 +315,9 @@
 		}
 	}
 
-	QofQueryPredData *pred;
 	pred = qof_query_guid_predicate (sm, guid_list);
 
 	/* The predicate made a copy of everything, so free our stuff */
-   GList *n;
 	for (n=guid_list; n; n=n->next)
 	{
 		guid_free (n->data);
@@ -331,11 +331,12 @@
 static QofQueryPredData *
 qof_query_pred_char_from_xml (xmlNodePtr root)
 {
+	QofQueryPredData *pred;
+	QofCharMatch sm = QOF_CHAR_MATCH_ANY;
+   const char * char_list = NULL;
 	xmlNodePtr xp = root->xmlChildrenNode;
 	xmlNodePtr node;
 
-	QofCharMatch sm = QOF_CHAR_MATCH_ANY;
-   const char * char_list = NULL;
 
 	for (node=xp; node; node = node->next)
 	{
@@ -348,7 +349,6 @@
 		{}
 	}
 
-	QofQueryPredData *pred;
 	pred = qof_query_char_predicate (sm, char_list);
 	return pred;
 }
@@ -358,11 +358,12 @@
 static QofQueryPredData *
 qof_query_pred_numeric_from_xml (xmlNodePtr root)
 {
+	QofQueryCompare how = QOF_COMPARE_EQUAL;
+	QofNumericMatch sm = QOF_NUMERIC_MATCH_ANY;
+	QofQueryPredData *pred;
 	xmlNodePtr xp = root->xmlChildrenNode;
 	xmlNodePtr node;
 
-	QofQueryCompare how = QOF_COMPARE_EQUAL;
-	QofNumericMatch sm = QOF_NUMERIC_MATCH_ANY;
    gnc_numeric num;
 
 	for (node=xp; node; node = node->next)
@@ -376,7 +377,6 @@
 		{}
 	}
 
-	QofQueryPredData *pred;
 	pred = qof_query_numeric_predicate (how, sm, num);
 	return pred;
 }
@@ -386,12 +386,13 @@
 static QofQueryPredData *
 qof_query_pred_date_from_xml (xmlNodePtr root)
 {
-	xmlNodePtr xp = root->xmlChildrenNode;
-	xmlNodePtr node;
-
 	QofQueryCompare how = QOF_COMPARE_EQUAL;
 	QofDateMatch sm = QOF_DATE_MATCH_ROUNDED;
 	Timespec date = {0,0};
+	QofQueryPredData *pred;
+	xmlNodePtr xp = root->xmlChildrenNode;
+	xmlNodePtr node;
+
 
 	for (node=xp; node; node = node->next)
 	{
@@ -404,7 +405,6 @@
 		{}
 	}
 
-	QofQueryPredData *pred;
 	pred = qof_query_date_predicate (how, sm, date);
 	return pred;
 }
@@ -414,13 +414,14 @@
 static QofQueryPredData *
 qof_query_pred_string_from_xml (xmlNodePtr root)
 {
-	xmlNodePtr xp = root->xmlChildrenNode;
-	xmlNodePtr node;
-
 	QofQueryCompare how = QOF_COMPARE_EQUAL;
 	QofStringMatch sm = QOF_STRING_MATCH_CASEINSENSITIVE;
 	gboolean is_regex = FALSE;
 	const char *pstr = NULL;
+	QofQueryPredData *pred;
+	xmlNodePtr xp = root->xmlChildrenNode;
+	xmlNodePtr node;
+
 
 	for (node=xp; node; node = node->next)
 	{
@@ -434,7 +435,6 @@
 		{}
 	}
 
-	QofQueryPredData *pred;
 	pred = qof_query_string_predicate (how, pstr, sm , is_regex);
 	return pred;
 }
@@ -444,8 +444,8 @@
 static GSList * 
 qof_query_param_path_from_xml (xmlNodePtr root)
 {
-	xmlNodePtr pterms = root->xmlChildrenNode;
 	GSList *plist = NULL;
+	xmlNodePtr pterms = root->xmlChildrenNode;
 	xmlNodePtr node;
 	for (node=pterms; node; node = node->next)
 	{
@@ -465,10 +465,10 @@
 static void 
 qof_query_term_from_xml (QofQuery *q, xmlNodePtr root)
 {
-	xmlNodePtr node;
-	xmlNodePtr term = root->xmlChildrenNode;
 	QofQueryPredData *pred = NULL;
 	GSList *path = NULL;
+	xmlNodePtr node;
+	xmlNodePtr term = root->xmlChildrenNode;
 
 	for (node=term; node; node = node->next)
 	{
@@ -476,8 +476,9 @@
 		if (0 == strcmp (node->name, "qofquery:invert"))
 		{
 			QofQuery *qt = qof_query_create();
+			QofQuery *qinv;
 			qof_query_term_from_xml (qt, node);
-			QofQuery *qinv = qof_query_invert (qt);
+			qinv = qof_query_invert (qt);
 			qof_query_merge_in_place (q, qinv, QOF_QUERY_AND);
 			qof_query_destroy (qinv);
 			qof_query_destroy (qt);
@@ -594,10 +595,14 @@
 qof_query_from_xml (xmlNodePtr root)
 {
 	QofQuery *q;
+	xmlChar *version;
+	xmlNodePtr qpart;
+	xmlNodePtr node;
 
 	if (!root) return NULL;
 
-	xmlChar * version = xmlGetProp(root, "version");
+	version = xmlGetProp(root, "version");
+
    if (!root->name || strcmp ("qof:qofquery", root->name))
    {
 		// XXX something is wrong. warn ... 
@@ -606,8 +611,7 @@
 
 	q = qof_query_create ();
 
-	xmlNodePtr qpart = root->xmlChildrenNode;
-	xmlNodePtr node;
+	qpart = root->xmlChildrenNode;
 	for (node=qpart; node; node = node->next)
 	{
 		if (node->type != XML_ELEMENT_NODE) continue;
