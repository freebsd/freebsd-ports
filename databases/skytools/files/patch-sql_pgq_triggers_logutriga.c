--- sql/pgq/triggers/logutriga.c.orig	2019-08-05 04:38:03 UTC
+++ sql/pgq/triggers/logutriga.c
@@ -54,7 +54,11 @@ static int is_interesting_change(PgqTriggerEvent *ev, 
 		/*
 		 * Ignore dropped columns
 		 */
+#if PG_VERSION_NUM < 110000
 		if (tupdesc->attrs[i]->attisdropped)
+#else
+		if (TupleDescAttr(tupdesc, i)->attisdropped)
+#endif
 			continue;
 		attkind_idx++;
 
@@ -145,7 +149,11 @@ void pgq_urlenc_row(PgqTriggerEvent *ev, HeapTuple row
 
 	for (i = 0; i < tg->tg_relation->rd_att->natts; i++) {
 		/* Skip dropped columns */
+#if PG_VERSION_NUM < 110000
 		if (tupdesc->attrs[i]->attisdropped)
+#else
+		if (TupleDescAttr(tupdesc, i)->attisdropped)
+#endif
 			continue;
 
 		attkind_idx++;
