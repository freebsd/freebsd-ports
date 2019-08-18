--- src/plpl.c.orig	2019-08-04 04:35:14 UTC
+++ src/plpl.c
@@ -137,12 +137,21 @@ pl_query_name(VALUE obj)
     }
     res = rb_ary_new2(tpl->dsc->natts);
     for (i = 0; i < tpl->dsc->natts; i++) {
+#if PG_VERSION_NUM < 110000
         if (tpl->dsc->attrs[i]->attisdropped) {
             attname = "";
         }
         else {
             attname = NameStr(tpl->dsc->attrs[i]->attname);
         }
+#else
+        if (TupleDescAttr(tpl->dsc, i)->attisdropped) {
+            attname = "";
+        }
+        else {
+            attname = NameStr(TupleDescAttr(tpl->dsc, i)->attname);
+        }
+#endif
         rb_ary_push(res, rb_tainted_str_new2(attname));
     }
     return res;
@@ -178,6 +187,7 @@ pl_query_type(VALUE obj)
     }
     res = rb_ary_new2(tpl->dsc->natts);
     for (i = 0; i < tpl->dsc->natts; i++) {
+#if PG_VERSION_NUM < 110000
         if (tpl->dsc->attrs[i]->attisdropped)
             continue;
         PLRUBY_BEGIN(1);
@@ -189,6 +199,19 @@ pl_query_type(VALUE obj)
             rb_raise(pl_ePLruby, "Cache lookup for attribute '%s' type %ld failed",
                      attname, OidGD(tpl->dsc->attrs[i]->atttypid));
         }
+#else
+        if (TupleDescAttr(tpl->dsc, i)->attisdropped)
+            continue;
+        PLRUBY_BEGIN(1);
+        attname = NameStr(TupleDescAttr(tpl->dsc, i)->attname);
+        typeTup = SearchSysCache(TYPEOID, OidGD(TupleDescAttr(tpl->dsc, i)->atttypid),
+                                 0, 0, 0);
+        PLRUBY_END;
+        if (!HeapTupleIsValid(typeTup)) {
+            rb_raise(pl_ePLruby, "Cache lookup for attribute '%s' type %ld failed",
+                     attname, OidGD(TupleDescAttr(tpl->dsc, i)->atttypid));
+        }
+#endif
         fpgt = (Form_pg_type) GETSTRUCT(typeTup);
         rb_ary_push(res, rb_tainted_str_new2(NameStr(fpgt->typname)));
         ReleaseSysCache(typeTup);
@@ -588,14 +611,23 @@ pl_tuple_heap(VALUE c, VALUE tuple)
     MEMZERO(nulls, char, RARRAY_LEN(c));
     for (i = 0; i < RARRAY_LEN(c); i++) {
         if (NIL_P(RARRAY_PTR(c)[i]) || 
+#if PG_VERSION_NUM < 110000
             tupdesc->attrs[i]->attisdropped) {
+#else
+            TupleDescAttr(tupdesc, i)->attisdropped) {
+#endif
             dvalues[i] = (Datum)0;
             nulls[i] = 'n';
         }
         else {
             nulls[i] = ' ';
+#if PG_VERSION_NUM < 110000
             typid =  tupdesc->attrs[i]->atttypid;
             if (tupdesc->attrs[i]->attndims != 0 ||
+#else
+            typid =  TupleDescAttr(tupdesc, i)->atttypid;
+            if (TupleDescAttr(tupdesc, i)->attndims != 0 ||
+#endif
 		tpl->att->attinfuncs[i].fn_addr == (PGFunction)array_in) {
                 pl_proc_desc prodesc;
                 FmgrInfo func;
@@ -1088,6 +1120,7 @@ plruby_build_tuple(HeapTuple tuple, TupleDesc tupdesc,
     }
 
     for (i = 0; i < tupdesc->natts; i++) {
+#if PG_VERSION_NUM < 110000
         if (tupdesc->attrs[i]->attisdropped)
             continue;
         PLRUBY_BEGIN(1);
@@ -1101,7 +1134,21 @@ plruby_build_tuple(HeapTuple tuple, TupleDesc tupdesc,
             rb_raise(pl_ePLruby, "Cache lookup for attribute '%s' type %ld failed",
                      attname, OidGD(tupdesc->attrs[i]->atttypid));
         }
+#else
+        if (TupleDescAttr(tupdesc, i)->attisdropped)
+            continue;
+        PLRUBY_BEGIN(1);
+        attname = NameStr(TupleDescAttr(tupdesc, i)->attname);
+        attr = heap_getattr(tuple, i + 1, tupdesc, &isnull);
+        typeTup = SearchSysCache(TYPEOID, OidGD(TupleDescAttr(tupdesc, i)->atttypid),
+                                 0, 0, 0);
+        PLRUBY_END;
 
+        if (!HeapTupleIsValid(typeTup)) {
+            rb_raise(pl_ePLruby, "Cache lookup for attribute '%s' type %ld failed",
+                     attname, OidGD(TupleDescAttr(tupdesc, i)->atttypid));
+        }
+#endif
         fpgt = (Form_pg_type) GETSTRUCT(typeTup);
         typoutput = (Oid) (fpgt->typoutput);
 #if PG_PL_VERSION >= 75
@@ -1115,6 +1162,7 @@ plruby_build_tuple(HeapTuple tuple, TupleDesc tupdesc,
             int alen;
 
             typname = NameStr(fpgt->typname);
+#if PG_VERSION_NUM < 110000
             alen = tupdesc->attrs[i]->attlen;
             typeid = tupdesc->attrs[i]->atttypid;
             if (strcmp(typname, "text") == 0) {
@@ -1129,6 +1177,22 @@ plruby_build_tuple(HeapTuple tuple, TupleDesc tupdesc,
                     alen = tupdesc->attrs[i]->atttypmod - 4;
                 }
             }
+#else
+            alen = TupleDescAttr(tupdesc, i)->attlen;
+            typeid = TupleDescAttr(tupdesc, i)->atttypid;
+            if (strcmp(typname, "text") == 0) {
+                alen = -1;
+            }
+            else if (strcmp(typname, "bpchar") == 0 ||
+                     strcmp(typname, "varchar") == 0) {
+                if (TupleDescAttr(tupdesc, i)->atttypmod == -1) {
+                    alen = 0;
+                }
+                else {
+                    alen = TupleDescAttr(tupdesc, i)->atttypmod - 4;
+                }
+            }
+#endif
             if ((type_ret & RET_DESC_ARR) == RET_DESC_ARR) {
                 res = rb_ary_new();
                 rb_ary_push(res, rb_tainted_str_new2(attname));
@@ -1190,8 +1254,13 @@ plruby_build_tuple(HeapTuple tuple, TupleDesc tupdesc,
                 
                 fmgr_info(typoutput, &finfo);
                 
+#if PG_VERSION_NUM < 110000
                 s = pl_convert_arg(attr, tupdesc->attrs[i]->atttypid,
                                    &finfo, typelem,tupdesc->attrs[i]->attlen);
+#else
+                s = pl_convert_arg(attr, tupdesc->attrs[i].atttypid,
+                                   &finfo, typelem, TupleDescAttr(tupdesc, i)->attlen);
+#endif
             }
             PLRUBY_END_PROTECT;
 
