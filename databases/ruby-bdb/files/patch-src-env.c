--- src/env.c.orig	2011-04-06 19:35:39 UTC
+++ src/env.c
@@ -67,8 +67,8 @@ bdb_env_rep_transport(DB_ENV *env, const DBT *control,
     lsnobj = bdb_makelsn(obj);
     Data_Get_Struct(lsnobj, struct dblsnst, lsnst);
     MEMCPY(lsnst->lsn, lsn, DB_LSN, 1);
-    av = rb_tainted_str_new(control->data, control->size);
-    bv = rb_tainted_str_new(rec->data, rec->size);
+    av = rb_str_new(control->data, control->size);
+    bv = rb_str_new(rec->data, rec->size);
     if (envst->rep_transport == 0) {
 	res = rb_funcall(obj, rb_intern("bdb_rep_transport"), 5, av, bv, lsnobj,
 			 INT2FIX(envid), INT2FIX(flags));
@@ -90,8 +90,8 @@ bdb_env_rep_transport(DB_ENV *env, const DBT *control,
     bdb_ENV *envst;
 
     GetIdEnv(obj, envst);
-    av = rb_tainted_str_new(control->data, control->size);
-    bv = rb_tainted_str_new(rec->data, rec->size);
+    av = rb_str_new(control->data, control->size);
+    bv = rb_str_new(rec->data, rec->size);
     if (envst->rep_transport == 0) {
 	res = rb_funcall(obj, rb_intern("bdb_rep_transport"), 4, av, bv,
 			 INT2FIX(envid), INT2FIX(flags));
@@ -328,10 +328,10 @@ bdb_env_msgcall(const DB_ENV *dbenv, const char *msg)
 	return;
     }
     if (envst->msgcall == 0) {
-	rb_funcall(obj, id_msgcall, 1, rb_tainted_str_new2(msg));
+	rb_funcall(obj, id_msgcall, 1, rb_str_new_cstr(msg));
     }
     else {
-	rb_funcall(envst->msgcall, bdb_id_call, 1, rb_tainted_str_new2(msg));
+	rb_funcall(envst->msgcall, bdb_id_call, 1, rb_str_new_cstr(msg));
     }
 }
 
@@ -508,7 +508,7 @@ bdb_env_set_notify(VALUE obj, VALUE a)
 
 
 static VALUE
-bdb_env_i_options(VALUE obj, VALUE db_stobj)
+bdb_env_i_options(VALUE obj, VALUE db_stobj, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
     char *options;
     DB_ENV *envp;
@@ -1121,9 +1121,11 @@ bdb_env_close(VALUE obj)
 {
     bdb_ENV *envst;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (!OBJ_TAINTED(obj) && rb_safe_level() >= 4) {
 	rb_raise(rb_eSecurityError, "Insecure: can't close the environnement");
     }
+#endif
     GetEnvDB(obj, envst);
     bdb_final(envst);
     RDATA(obj)->dfree = free;
@@ -1193,10 +1195,10 @@ bdb_env_open_db(int argc, VALUE *argv, VALUE obj)
 	argv[argc - 1] = rb_hash_new();
     }
     if (rb_obj_is_kind_of(obj, bdb_cEnv)) {
-	rb_hash_aset(argv[argc - 1], rb_tainted_str_new2("env"), obj);
+	rb_hash_aset(argv[argc - 1], rb_str_new_cstr("env"), obj);
     }
     else {
-	rb_hash_aset(argv[argc - 1], rb_tainted_str_new2("txn"), obj);
+	rb_hash_aset(argv[argc - 1], rb_str_new_cstr("txn"), obj);
     }
     return rb_funcall2(cl, rb_intern("new"), argc, argv);
 }
@@ -1206,7 +1208,7 @@ void
 bdb_env_errcall(const DB_ENV *env, const char *errpfx, const char *msg)
 {
     bdb_errcall = 1;
-    bdb_errstr = rb_tainted_str_new2(msg);
+    bdb_errstr = rb_str_new_cstr(msg);
 }
 
 #else
@@ -1215,7 +1217,7 @@ void
 bdb_env_errcall(const char *errpfx, char *msg)
 {
     bdb_errcall = 1;
-    bdb_errstr = rb_tainted_str_new2(msg);
+    bdb_errstr = rb_str_new_cstr(msg);
 }
 
 #endif
@@ -1303,7 +1305,7 @@ bdb_env_each_options(VALUE opt, VALUE stobj)
     DB_ENV *envp;
     struct db_stoptions *db_st;
 
-    res = rb_iterate(rb_each, opt, bdb_env_i_options, stobj);
+    res = rb_block_call(opt, rb_intern("each"), 0, NULL, bdb_env_i_options, stobj);
     Data_Get_Struct(stobj, struct db_stoptions, db_st);
     envp = db_st->env->envp;
 #if HAVE_ST_DB_ENV_SET_LG_BSIZE
@@ -1322,8 +1324,9 @@ bdb_env_each_options(VALUE opt, VALUE stobj)
 }
 
 static VALUE
-bdb_env_s_i_options(VALUE obj, int *flags)
+bdb_env_s_i_options(VALUE obj, VALUE pflags, int _argc, const VALUE *_argv, VALUE _blockarg)
 {
+    int *flags = (int *)pflags;
     char *options;
     VALUE key, value;
 
@@ -1394,7 +1397,7 @@ bdb_env_s_new(int argc, VALUE *argv, VALUE obj)
     envst->envp->db_errcall = bdb_env_errcall;
 #else
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
-	rb_iterate(rb_each, argv[argc - 1], bdb_env_s_i_options, (VALUE)&flags);
+	rb_block_call(argv[argc - 1], rb_intern("each"), 0, NULL, bdb_env_s_i_options, (VALUE)&flags);
     }
     bdb_test_error(db_env_create(&(envst->envp), flags));
     envst->envp->set_errpfx(envst->envp, "BDB::");
@@ -1406,7 +1409,7 @@ bdb_env_s_new(int argc, VALUE *argv, VALUE obj)
     if (argc && TYPE(argv[argc - 1]) == T_HASH) {
 	VALUE value = Qnil;
 
-	rb_iterate(rb_each, argv[argc - 1], bdb_env_s_j_options, (VALUE)&value);
+	rb_block_call(argv[argc - 1], rb_intern("each"), 0, NULL, bdb_env_s_j_options, (VALUE)&value);
 	if (!NIL_P(value)) {
 	    if (!rb_respond_to(value, bdb_id_call)) {
 		rb_raise(bdb_eFatal, "arg must respond to #call");
@@ -1517,12 +1520,16 @@ bdb_env_init(int argc, VALUE *argv, VALUE obj)
 	flags = NUM2INT(c);
         break;
     }
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 4
     if (flags & DB_CREATE) {
 	rb_secure(4);
     }
+#endif
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 1
     if (flags & DB_USE_ENVIRON) {
 	rb_secure(1);
     }
+#endif
 #ifndef BDB_NO_THREAD_COMPILE
     if (!(envst->options & BDB_NO_THREAD)) {
 	bdb_set_func(envst);
@@ -1621,7 +1628,7 @@ bdb_env_init(int argc, VALUE *argv, VALUE obj)
 	envst->options |= BDB_AUTO_COMMIT;
     }
 #endif
-    envst->home = rb_tainted_str_new2(db_home);
+    envst->home = rb_str_new_cstr(db_home);
     OBJ_FREEZE(envst->home);
 #if HAVE_CONST_DB_INIT_REP
     if (flags & DB_INIT_REP) {
@@ -1658,7 +1665,9 @@ bdb_env_s_remove(int argc, VALUE *argv, VALUE obj)
     char *db_home;
     int flag = 0;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     rb_secure(2);
+#endif
     if (rb_scan_args(argc, argv, "11", &a, &b) == 2) {
 	flag = NUM2INT(b);
     }
@@ -1754,13 +1763,13 @@ bdb_thread_init(int argc, VALUE *argv, VALUE obj)
     if (rb_block_given_p()) {
 #if HAVE_RB_BLOCK_CALL
 	return rb_block_call(obj, rb_intern("__bdb_thread_init__"), argc, argv,
-			     rb_yield, obj);
+			     (rb_block_call_func_t)rb_yield, obj);
 #else
 	VALUE tmp[3];
 	tmp[0] = obj;
 	tmp[1] = (VALUE)argc;
 	tmp[2] = (VALUE)argv;
-	return rb_iterate((VALUE (*)(VALUE))bdb_env_iterate, (VALUE)tmp, rb_yield, obj);
+	return rb_block_call((VALUE)tmp, bdb_env_iterate, 0, NULL, (rb_block_call_func_t)rb_yield, obj);
 #endif
     }
     return rb_funcall2(obj, rb_intern("__bdb_thread_init__"), argc, argv);
@@ -1828,7 +1837,7 @@ bdb_env_i_conf(VALUE obj, VALUE a)
 	res = rb_ary_new();
 	if (dirs) {
 	    for (i = 0; dirs[i] != NULL; i++) {
-		rb_ary_push(res, rb_tainted_str_new2(dirs[i]));
+		rb_ary_push(res, rb_str_new_cstr(dirs[i]));
 	    }
 	}
 	return res;
@@ -1844,7 +1853,7 @@ bdb_env_i_conf(VALUE obj, VALUE a)
     if (strcmp(str, "home") == 0) {
 	bdb_test_error(envst->envp->get_home(envst->envp, &strval));
 	if (strval && strlen(strval)) {
-	    return rb_tainted_str_new2(strval);
+	    return rb_str_new_cstr(strval);
 	}
 	return Qnil;
     }
@@ -1859,7 +1868,7 @@ bdb_env_i_conf(VALUE obj, VALUE a)
     if (strcmp(str, "lg_dir") == 0) {
 	bdb_test_error(envst->envp->get_lg_dir(envst->envp, &strval));
 	if (strval && strlen(strval)) {
-	    return rb_tainted_str_new2(strval);
+	    return rb_str_new_cstr(strval);
 	}
 	return Qnil;
     }
@@ -1961,7 +1970,7 @@ bdb_env_i_conf(VALUE obj, VALUE a)
     if (strcmp(str, "tmp_dir") == 0) {
 	bdb_test_error(envst->envp->get_tmp_dir(envst->envp, &strval));
 	if (strval && strlen(strval)) {
-	    return rb_tainted_str_new2(strval);
+	    return rb_str_new_cstr(strval);
 	}
 	return Qnil;
     }
@@ -2343,10 +2352,10 @@ bdb_env_repmgr_site_list(VALUE obj)
     res = rb_ary_new();
     for (i = 0; i < count; i++) {
 	tmp = rb_hash_new();
-	rb_hash_aset(tmp, rb_tainted_str_new2("eid"), INT2NUM(list[i].eid));
-	rb_hash_aset(tmp, rb_tainted_str_new2("host"), rb_tainted_str_new2(list[i].host));
-	rb_hash_aset(tmp, rb_tainted_str_new2("port"), INT2NUM(list[i].port));
-	rb_hash_aset(tmp, rb_tainted_str_new2("status"), INT2NUM(list[i].status));
+	rb_hash_aset(tmp, rb_str_new_cstr("eid"), INT2NUM(list[i].eid));
+	rb_hash_aset(tmp, rb_str_new_cstr("host"), rb_str_new_cstr(list[i].host));
+	rb_hash_aset(tmp, rb_str_new_cstr("port"), INT2NUM(list[i].port));
+	rb_hash_aset(tmp, rb_str_new_cstr("status"), INT2NUM(list[i].status));
 	rb_ary_push(res, tmp);
     }
     free(list);
@@ -2445,7 +2454,7 @@ bdb_env_rep_set_nsites(VALUE obj, VALUE a)
 }
 
 static VALUE
-bdb_env_rep_get_nsites(VALUE obj, VALUE a)
+bdb_env_rep_get_nsites(VALUE obj)
 {
     bdb_ENV *envst;
     int offon;
@@ -2470,7 +2479,7 @@ bdb_env_rep_set_priority(VALUE obj, VALUE a)
 }
 
 static VALUE
-bdb_env_rep_get_priority(VALUE obj, VALUE a)
+bdb_env_rep_get_priority(VALUE obj)
 {
     bdb_ENV *envst;
     int offon;
@@ -2571,102 +2580,102 @@ bdb_env_rep_stat(int argc, VALUE *argv, VALUE obj)
     bdb_test_error(envst->envp->rep_stat(envst->envp, &bs, flags));
     a = rb_hash_new();
 #if HAVE_ST_DB_REP_STAT_ST_BULK_FILLS
-    rb_hash_aset(a, rb_tainted_str_new2("st_bulk_fills"), INT2NUM(bs->st_bulk_fills));
+    rb_hash_aset(a, rb_str_new_cstr("st_bulk_fills"), INT2NUM(bs->st_bulk_fills));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_BULK_OVERFLOWS
-    rb_hash_aset(a, rb_tainted_str_new2("st_bulk_overflows"), INT2NUM(bs->st_bulk_overflows));
+    rb_hash_aset(a, rb_str_new_cstr("st_bulk_overflows"), INT2NUM(bs->st_bulk_overflows));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_BULK_RECORDS
-    rb_hash_aset(a, rb_tainted_str_new2("st_bulk_records"), INT2NUM(bs->st_bulk_records));
+    rb_hash_aset(a, rb_str_new_cstr("st_bulk_records"), INT2NUM(bs->st_bulk_records));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_BULK_TRANSFERS
-    rb_hash_aset(a, rb_tainted_str_new2("st_bulk_transfers"), INT2NUM(bs->st_bulk_transfers));
+    rb_hash_aset(a, rb_str_new_cstr("st_bulk_transfers"), INT2NUM(bs->st_bulk_transfers));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_CLIENT_REREQUESTS
-    rb_hash_aset(a, rb_tainted_str_new2("st_client_rerequests"), INT2NUM(bs->st_client_rerequests));
+    rb_hash_aset(a, rb_str_new_cstr("st_client_rerequests"), INT2NUM(bs->st_client_rerequests));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_CLIENT_SVC_MISS
-    rb_hash_aset(a, rb_tainted_str_new2("st_client_svc_miss"), INT2NUM(bs->st_client_svc_miss));
+    rb_hash_aset(a, rb_str_new_cstr("st_client_svc_miss"), INT2NUM(bs->st_client_svc_miss));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_CLIENT_SVC_REQ
-    rb_hash_aset(a, rb_tainted_str_new2("st_client_svc_req"), INT2NUM(bs->st_client_svc_req));
+    rb_hash_aset(a, rb_str_new_cstr("st_client_svc_req"), INT2NUM(bs->st_client_svc_req));
 #endif
-    rb_hash_aset(a, rb_tainted_str_new2("st_dupmasters"), INT2NUM(bs->st_dupmasters));
+    rb_hash_aset(a, rb_str_new_cstr("st_dupmasters"), INT2NUM(bs->st_dupmasters));
 #if HAVE_ST_DB_REP_STAT_ST_EGEN
-    rb_hash_aset(a, rb_tainted_str_new2("st_egen"), INT2NUM(bs->st_egen));
+    rb_hash_aset(a, rb_str_new_cstr("st_egen"), INT2NUM(bs->st_egen));
 #endif
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_cur_winner"), INT2NUM(bs->st_election_cur_winner));
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_gen"), INT2NUM(bs->st_election_gen));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_cur_winner"), INT2NUM(bs->st_election_cur_winner));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_gen"), INT2NUM(bs->st_election_gen));
 
     lsn = bdb_makelsn(obj);
     Data_Get_Struct(lsn, struct dblsnst, lsnst);
     MEMCPY(lsnst->lsn, &bs->st_election_lsn, DB_LSN, 1);
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_lsn"), lsn);
+    rb_hash_aset(a, rb_str_new_cstr("st_election_lsn"), lsn);
 
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_nsites"), INT2NUM(bs->st_election_nsites));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_nsites"), INT2NUM(bs->st_election_nsites));
 #if HAVE_ST_DB_REP_STAT_ST_ELECTION_NVOTES
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_nvotes"), INT2NUM(bs->st_election_nvotes));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_nvotes"), INT2NUM(bs->st_election_nvotes));
 #endif
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_priority"), INT2NUM(bs->st_election_priority));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_priority"), INT2NUM(bs->st_election_priority));
 #if HAVE_ST_DB_REP_STAT_ST_ELECTION_SEC
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_sec"), INT2NUM(bs->st_election_sec));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_sec"), INT2NUM(bs->st_election_sec));
 #endif
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_status"), INT2NUM(bs->st_election_status));
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_tiebreaker"), INT2NUM(bs->st_election_tiebreaker));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_status"), INT2NUM(bs->st_election_status));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_tiebreaker"), INT2NUM(bs->st_election_tiebreaker));
 #if HAVE_ST_DB_REP_STAT_ST_ELECTION_USEC
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_usec"), INT2NUM(bs->st_election_usec));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_usec"), INT2NUM(bs->st_election_usec));
 #endif
-    rb_hash_aset(a, rb_tainted_str_new2("st_election_votes"), INT2NUM(bs->st_election_votes));
-    rb_hash_aset(a, rb_tainted_str_new2("st_elections"), INT2NUM(bs->st_elections));
-    rb_hash_aset(a, rb_tainted_str_new2("st_elections_won"), INT2NUM(bs->st_elections_won));
-    rb_hash_aset(a, rb_tainted_str_new2("st_env_id"), INT2NUM(bs->st_env_id));
-    rb_hash_aset(a, rb_tainted_str_new2("st_env_priority"), INT2NUM(bs->st_env_priority));
-    rb_hash_aset(a, rb_tainted_str_new2("st_gen"), INT2NUM(bs->st_gen));
-    rb_hash_aset(a, rb_tainted_str_new2("st_log_duplicated"), INT2NUM(bs->st_log_duplicated));
-    rb_hash_aset(a, rb_tainted_str_new2("st_log_queued"), INT2NUM(bs->st_log_queued));
-    rb_hash_aset(a, rb_tainted_str_new2("st_log_queued_max"), INT2NUM(bs->st_log_queued_max));
-    rb_hash_aset(a, rb_tainted_str_new2("st_log_queued_total"), INT2NUM(bs->st_log_queued_total));
-    rb_hash_aset(a, rb_tainted_str_new2("st_log_records"), INT2NUM(bs->st_log_records));
-    rb_hash_aset(a, rb_tainted_str_new2("st_log_requested"), INT2NUM(bs->st_log_requested));
-    rb_hash_aset(a, rb_tainted_str_new2("st_master"), INT2NUM(bs->st_master));
-    rb_hash_aset(a, rb_tainted_str_new2("st_master_changes"), INT2NUM(bs->st_master_changes));
-    rb_hash_aset(a, rb_tainted_str_new2("st_msgs_badgen"), INT2NUM(bs->st_msgs_badgen));
-    rb_hash_aset(a, rb_tainted_str_new2("st_msgs_processed"), INT2NUM(bs->st_msgs_processed));
-    rb_hash_aset(a, rb_tainted_str_new2("st_msgs_recover"), INT2NUM(bs->st_msgs_recover));
-    rb_hash_aset(a, rb_tainted_str_new2("st_msgs_send_failures"), INT2NUM(bs->st_msgs_send_failures));
-    rb_hash_aset(a, rb_tainted_str_new2("st_msgs_sent"), INT2NUM(bs->st_msgs_sent));
-    rb_hash_aset(a, rb_tainted_str_new2("st_newsites"), INT2NUM(bs->st_newsites));
+    rb_hash_aset(a, rb_str_new_cstr("st_election_votes"), INT2NUM(bs->st_election_votes));
+    rb_hash_aset(a, rb_str_new_cstr("st_elections"), INT2NUM(bs->st_elections));
+    rb_hash_aset(a, rb_str_new_cstr("st_elections_won"), INT2NUM(bs->st_elections_won));
+    rb_hash_aset(a, rb_str_new_cstr("st_env_id"), INT2NUM(bs->st_env_id));
+    rb_hash_aset(a, rb_str_new_cstr("st_env_priority"), INT2NUM(bs->st_env_priority));
+    rb_hash_aset(a, rb_str_new_cstr("st_gen"), INT2NUM(bs->st_gen));
+    rb_hash_aset(a, rb_str_new_cstr("st_log_duplicated"), INT2NUM(bs->st_log_duplicated));
+    rb_hash_aset(a, rb_str_new_cstr("st_log_queued"), INT2NUM(bs->st_log_queued));
+    rb_hash_aset(a, rb_str_new_cstr("st_log_queued_max"), INT2NUM(bs->st_log_queued_max));
+    rb_hash_aset(a, rb_str_new_cstr("st_log_queued_total"), INT2NUM(bs->st_log_queued_total));
+    rb_hash_aset(a, rb_str_new_cstr("st_log_records"), INT2NUM(bs->st_log_records));
+    rb_hash_aset(a, rb_str_new_cstr("st_log_requested"), INT2NUM(bs->st_log_requested));
+    rb_hash_aset(a, rb_str_new_cstr("st_master"), INT2NUM(bs->st_master));
+    rb_hash_aset(a, rb_str_new_cstr("st_master_changes"), INT2NUM(bs->st_master_changes));
+    rb_hash_aset(a, rb_str_new_cstr("st_msgs_badgen"), INT2NUM(bs->st_msgs_badgen));
+    rb_hash_aset(a, rb_str_new_cstr("st_msgs_processed"), INT2NUM(bs->st_msgs_processed));
+    rb_hash_aset(a, rb_str_new_cstr("st_msgs_recover"), INT2NUM(bs->st_msgs_recover));
+    rb_hash_aset(a, rb_str_new_cstr("st_msgs_send_failures"), INT2NUM(bs->st_msgs_send_failures));
+    rb_hash_aset(a, rb_str_new_cstr("st_msgs_sent"), INT2NUM(bs->st_msgs_sent));
+    rb_hash_aset(a, rb_str_new_cstr("st_newsites"), INT2NUM(bs->st_newsites));
 
     lsn = bdb_makelsn(obj);
     Data_Get_Struct(lsn, struct dblsnst, lsnst);
     MEMCPY(lsnst->lsn, &bs->st_next_lsn, DB_LSN, 1);
-    rb_hash_aset(a, rb_tainted_str_new2("st_next_lsn"), lsn);
+    rb_hash_aset(a, rb_str_new_cstr("st_next_lsn"), lsn);
 #if HAVE_ST_DB_REP_STAT_ST_NEXT_PG
-    rb_hash_aset(a, rb_tainted_str_new2("st_next_pg"), INT2NUM(bs->st_next_pg));
+    rb_hash_aset(a, rb_str_new_cstr("st_next_pg"), INT2NUM(bs->st_next_pg));
 #endif
-    rb_hash_aset(a, rb_tainted_str_new2("st_nsites"), INT2NUM(bs->st_nsites));
-    rb_hash_aset(a, rb_tainted_str_new2("st_nthrottles"), INT2NUM(bs->st_nthrottles));
-    rb_hash_aset(a, rb_tainted_str_new2("st_outdated"), INT2NUM(bs->st_outdated));
+    rb_hash_aset(a, rb_str_new_cstr("st_nsites"), INT2NUM(bs->st_nsites));
+    rb_hash_aset(a, rb_str_new_cstr("st_nthrottles"), INT2NUM(bs->st_nthrottles));
+    rb_hash_aset(a, rb_str_new_cstr("st_outdated"), INT2NUM(bs->st_outdated));
 #if HAVE_ST_DB_REP_STAT_ST_PG_DUPLICATED
-    rb_hash_aset(a, rb_tainted_str_new2("st_pg_duplicated"), INT2NUM(bs->st_pg_duplicated));
+    rb_hash_aset(a, rb_str_new_cstr("st_pg_duplicated"), INT2NUM(bs->st_pg_duplicated));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_PG_RECORDS
-    rb_hash_aset(a, rb_tainted_str_new2("st_pg_records"), INT2NUM(bs->st_pg_records));
+    rb_hash_aset(a, rb_str_new_cstr("st_pg_records"), INT2NUM(bs->st_pg_records));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_PG_REQUESTED
-    rb_hash_aset(a, rb_tainted_str_new2("st_pg_requested"), INT2NUM(bs->st_pg_requested));
+    rb_hash_aset(a, rb_str_new_cstr("st_pg_requested"), INT2NUM(bs->st_pg_requested));
 #endif
 #if HAVE_ST_DB_REP_STAT_ST_STARTUP_COMPLETE
-    rb_hash_aset(a, rb_tainted_str_new2("st_startup_complete"), INT2NUM(bs->st_startup_complete));
+    rb_hash_aset(a, rb_str_new_cstr("st_startup_complete"), INT2NUM(bs->st_startup_complete));
 #endif
-    rb_hash_aset(a, rb_tainted_str_new2("st_status"), INT2NUM(bs->st_status));
-    rb_hash_aset(a, rb_tainted_str_new2("st_txns_applied"), INT2NUM(bs->st_txns_applied));
+    rb_hash_aset(a, rb_str_new_cstr("st_status"), INT2NUM(bs->st_status));
+    rb_hash_aset(a, rb_str_new_cstr("st_txns_applied"), INT2NUM(bs->st_txns_applied));
     lsn = bdb_makelsn(obj);
     Data_Get_Struct(lsn, struct dblsnst, lsnst);
     MEMCPY(lsnst->lsn, &bs->st_waiting_lsn, DB_LSN, 1);
-    rb_hash_aset(a, rb_tainted_str_new2("st_waiting_lsn"), lsn);
+    rb_hash_aset(a, rb_str_new_cstr("st_waiting_lsn"), lsn);
 #if HAVE_ST_DB_REP_STAT_ST_WAITING_PG
-    rb_hash_aset(a, rb_tainted_str_new2("st_waiting_pg"), INT2NUM(bs->st_waiting_pg));
+    rb_hash_aset(a, rb_str_new_cstr("st_waiting_pg"), INT2NUM(bs->st_waiting_pg));
 #endif
     free(bs);
     return a;
@@ -2764,7 +2773,7 @@ bdb_env_rep_set_clockskew(VALUE obj, VALUE a, VALUE b)
 }
 
 static VALUE
-bdb_env_rep_get_clockskew(VALUE obj, VALUE a)
+bdb_env_rep_get_clockskew(VALUE obj)
 {
     bdb_ENV *envst;
     u_int32_t fast, slow;
@@ -2791,7 +2800,7 @@ bdb_env_rep_set_request(VALUE obj, VALUE a, VALUE b)
 }
 
 static VALUE
-bdb_env_rep_get_request(VALUE obj, VALUE a)
+bdb_env_rep_get_request(VALUE obj)
 {
     bdb_ENV *envst;
     u_int32_t frmin, frmax;
@@ -2816,7 +2825,7 @@ bdb_env_dir_mode(VALUE obj)
     if (envst->envp->get_intermediate_dir_mode(envst->envp, &dir)) {
 	rb_raise(rb_eArgError, "invalid environment");
     }
-    return rb_tainted_str_new2(dir);
+    return rb_str_new_cstr(dir);
 }
 
 #endif
@@ -3012,7 +3021,7 @@ void bdb_init_env()
     rb_define_method(bdb_cEnv, "rep_timeout?", bdb_env_rep_intern_timeout, 1);
 #endif
 #if HAVE_ST_DB_ENV_REP_STAT
-    rb_define_method(bdb_cEnv, "rep_stat", bdb_env_rep_stat, 0);
+    rb_define_method(bdb_cEnv, "rep_stat", bdb_env_rep_stat, -1);
 #endif
 #if HAVE_ST_DB_ENV_REP_SYNC
     rb_define_method(bdb_cEnv, "rep_sync", bdb_env_rep_sync, -1);
