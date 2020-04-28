--- src/env.c.orig	2011-04-06 19:35:39 UTC
+++ src/env.c
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
@@ -1517,12 +1519,16 @@ bdb_env_init(int argc, VALUE *argv, VALUE obj)
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
@@ -1658,7 +1664,9 @@ bdb_env_s_remove(int argc, VALUE *argv, VALUE obj)
     char *db_home;
     int flag = 0;
 
+#if defined(RUBY_SAFE_LEVEL_MAX) && RUBY_SAFE_LEVEL_MAX >= 2
     rb_secure(2);
+#endif
     if (rb_scan_args(argc, argv, "11", &a, &b) == 2) {
 	flag = NUM2INT(b);
     }
