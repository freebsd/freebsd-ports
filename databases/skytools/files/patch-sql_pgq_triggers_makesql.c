--- sql/pgq/triggers/makesql.c.orig	2019-08-05 04:44:33 UTC
+++ sql/pgq/triggers/makesql.c
@@ -71,7 +71,11 @@ static void process_insert(PgqTriggerEvent *ev, String
 		char *col_ident;
 
 		/* Skip dropped columns */
+#if PG_VERSION_NUM < 110000
 		if (tupdesc->attrs[i]->attisdropped)
+#else
+		if (TupleDescAttr(tupdesc, i)->attisdropped)
+#endif
 			continue;
 
 		/* Check if allowed by colstring */
@@ -103,7 +107,11 @@ static void process_insert(PgqTriggerEvent *ev, String
 		char *col_value;
 
 		/* Skip dropped columns */
+#if PG_VERSION_NUM < 110000
 		if (tupdesc->attrs[i]->attisdropped)
+#else
+		if (TupleDescAttr(tupdesc, i)->attisdropped)
+#endif
 			continue;
 
 		/* Check if allowed by colstring */
@@ -154,7 +162,11 @@ static int process_update(PgqTriggerEvent *ev, StringI
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
@@ -240,7 +252,11 @@ static int process_update(PgqTriggerEvent *ev, StringI
 			return 0;
 
 		for (i = 0, attkind_idx = -1; i < tupdesc->natts; i++) {
+#if PG_VERSION_NUM < 110000
 			if (tupdesc->attrs[i]->attisdropped)
+#else
+			if (TupleDescAttr(tupdesc, i)->attisdropped)
+#endif
 				continue;
 
 			attkind_idx++;
@@ -259,7 +275,11 @@ static int process_update(PgqTriggerEvent *ev, StringI
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
@@ -291,7 +311,11 @@ static void process_delete(PgqTriggerEvent *ev, String
 	int attkind_idx;
 
 	for (i = 0, attkind_idx = -1; i < tupdesc->natts; i++) {
+#if PG_VERSION_NUM < 110000
 		if (tupdesc->attrs[i]->attisdropped)
+#else
+		if (TupleDescAttr(tupdesc, i)->attisdropped)
+#endif
 			continue;
 
 		attkind_idx++;
@@ -323,7 +347,11 @@ int pgqtriga_make_sql(PgqTriggerEvent *ev, StringInfo 
 	 * Count number of active columns
 	 */
 	for (i = 0, attcnt = 0; i < tupdesc->natts; i++) {
+#if PG_VERSION_NUM < 110000
 		if (tupdesc->attrs[i]->attisdropped)
+#else
+		if (TupleDescAttr(tupdesc, i)->attisdropped)
+#endif
 			continue;
 		attcnt++;
 	}
