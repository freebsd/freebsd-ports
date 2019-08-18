--- sql/pgq/triggers/common.c.orig	2019-08-05 04:40:08 UTC
+++ sql/pgq/triggers/common.c
@@ -125,9 +125,15 @@ static void fill_magic_columns(PgqTriggerEvent *ev)
 
 	for (i = 0; i < tupdesc->natts; i++) {
 		/* Skip dropped columns */
+#if PG_VERSION_NUM < 110000
 		if (tupdesc->attrs[i]->attisdropped)
 			continue;
 		col_name = NameStr(tupdesc->attrs[i]->attname);
+#else
+		if (TupleDescAttr(tupdesc, i)->attisdropped)
+			continue;
+		col_name = NameStr(TupleDescAttr(tupdesc, i)->attname);
+#endif
 		if (!is_magic_field(col_name))
 			continue;
 		if (strcmp(col_name, "_pgq_ev_type") == 0)
@@ -481,7 +487,11 @@ static void parse_oldstyle_args(PgqTriggerEvent *ev, T
 	 */
 	tupdesc = tg->tg_relation->rd_att;
 	for (i = 0, attcnt = 0; i < tupdesc->natts; i++) {
+#if PG_VERSION_NUM < 110000
 		if (!tupdesc->attrs[i]->attisdropped)
+#else
+		if (!TupleDescAttr(tupdesc, i)->attisdropped)
+#endif
 			attcnt++;
 	}
 
@@ -598,9 +608,15 @@ bool pgqtriga_skip_col(PgqTriggerEvent *ev, int i, int
 	const char *name;
 
 	tupdesc = tg->tg_relation->rd_att;
+#if PG_VERSION_NUM < 110000
 	if (tupdesc->attrs[i]->attisdropped)
 		return true;
 	name = NameStr(tupdesc->attrs[i]->attname);
+#else
+	if (TupleDescAttr(tupdesc, i)->attisdropped)
+		return true;
+	name = NameStr(TupleDescAttr(tupdesc, i)->attname);
+#endif
 
 	if (is_magic_field(name)) {
 		ev->tgargs->custom_fields = 1;
@@ -632,9 +648,15 @@ bool pgqtriga_is_pkey(PgqTriggerEvent *ev, int i, int 
 		return ev->attkind[attkind_idx] == 'k';
 	} else if (ev->pkey_list) {
 		tupdesc = tg->tg_relation->rd_att;
+#if PG_VERSION_NUM < 110000
 		if (tupdesc->attrs[i]->attisdropped)
 			return false;
 		name = NameStr(tupdesc->attrs[i]->attname);
+#else
+		if (TupleDescAttr(tupdesc, i)->attisdropped)
+			return false;
+		name = NameStr(TupleDescAttr(tupdesc, i)->attname);
+#endif
 		if (is_magic_field(name)) {
 			ev->tgargs->custom_fields = 1;
 			return false;
