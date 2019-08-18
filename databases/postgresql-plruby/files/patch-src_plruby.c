--- src/plruby.c.orig	2019-08-04 04:30:44 UTC
+++ src/plruby.c
@@ -1184,17 +1184,29 @@ for_numvals(obj, argobj)
         rb_raise(pl_ePLruby, "invalid attribute '%s'", RSTRING_PTR(key));
     }
     attnum -= 1;
+#if PG_VERSION_NUM < 110000
     if (arg->tupdesc->attrs[attnum]->attisdropped) {
+#else
+    if (TupleDescAttr(arg->tupdesc, attnum)->attisdropped) {
+#endif
         return Qnil;
     }
 
     PLRUBY_BEGIN(1);
     typeTup = SearchSysCache(TYPEOID,
+#if PG_VERSION_NUM < 110000
                              OidGD(arg->tupdesc->attrs[attnum]->atttypid),
+#else
+                             OidGD(TupleDescAttr(arg->tupdesc, attnum)->atttypid),
+#endif
                              0, 0, 0);
     if (!HeapTupleIsValid(typeTup)) {   
         rb_raise(pl_ePLruby, "Cache lookup for attribute '%s' type %ld failed",
+#if PG_VERSION_NUM < 110000
                  RSTRING_PTR(key), OidGD(arg->tupdesc->attrs[attnum]->atttypid));
+#else
+                 RSTRING_PTR(key), OidGD(TupleDescAttr(arg->tupdesc, attnum)->atttypid));
+#endif
     }
     fpg = (Form_pg_type) GETSTRUCT(typeTup);
     ReleaseSysCache(typeTup);
@@ -1226,11 +1238,19 @@ for_numvals(obj, argobj)
     else {
         arg->modvalues[attnum] = 
             plruby_to_datum(value, &finfo, 
+#if PG_VERSION_NUM < 110000
                             arg->tupdesc->attrs[attnum]->atttypid, 
                             fpg->typelem,
                             (!VARLENA_FIXED_SIZE(arg->tupdesc->attrs[attnum]))
                             ? arg->tupdesc->attrs[attnum]->attlen
                             : arg->tupdesc->attrs[attnum]->atttypmod);
+#else
+                            TupleDescAttr(arg->tupdesc, attnum)->atttypid, 
+                            fpg->typelem,
+                            (!VARLENA_FIXED_SIZE(TupleDescAttr(arg->tupdesc, attnum)))
+                            ? TupleDescAttr(arg->tupdesc, attnum)->attlen
+                            : TupleDescAttr(arg->tupdesc, attnum)->atttypmod);
+#endif
     }
     return Qnil;
 }
@@ -1284,12 +1304,21 @@ pl_trigger_handler(struct pl_thread_st *plth)
 
     tmp = rb_ary_new2(tupdesc->natts);
     for (i = 0; i < tupdesc->natts; i++) {
+#if PG_VERSION_NUM < 110000
         if (tupdesc->attrs[i]->attisdropped) {
             rb_ary_push(tmp, rb_str_freeze_new2(""));
         }
         else {
             rb_ary_push(tmp, rb_str_freeze_new2(NameStr(tupdesc->attrs[i]->attname)));
         }
+#else
+        if (TupleDescAttr(tupdesc, i)->attisdropped) {
+            rb_ary_push(tmp, rb_str_freeze_new2(""));
+        }
+        else {
+            rb_ary_push(tmp, rb_str_freeze_new2(NameStr(TupleDescAttr(tupdesc, i)->attname)));
+        }
+#endif
     }
     rb_hash_aset(TG, rb_str_freeze_new2("relatts"), rb_ary_freeze(tmp));
 
