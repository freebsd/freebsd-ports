
Upstream patch for building with PostgreSQL 10.x
https://github.com/zulip/tsearch_extras/issues/3

diff --git a/tsearch_extras.c b/tsearch_extras.c
index 062dcdb..7464c71 100644
--- tsearch_extras.c
+++ tsearch_extras.c
@@ -77,9 +77,15 @@ ts_match_locs_setup(Oid cfgId, TsMatchesData *mdata, text* in, TSQuery query)
 
 	hlparsetext(cfgId, &prs, query, VARDATA(in), VARSIZE(in) - VARHDRSZ);
 
+	#if PG_VERSION_NUM >= 100000
+	headline_options = lappend(headline_options,
+											  makeDefElem(pstrdup("HighlightAll"),
+											  (Node *) makeString(pstrdup("1")), -1));
+	#else
 	headline_options = lappend(headline_options,
 											  makeDefElem(pstrdup("HighlightAll"),
 											  (Node *) makeString(pstrdup("1"))));
+	#endif
 
 	FunctionCall3(&(prsobj->prsheadline),
 				  PointerGetDatum(&prs),
