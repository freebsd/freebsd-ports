--- dns-terror/DatedStringDb.cc.orig	2003-05-17 18:14:35 UTC
+++ dns-terror/DatedStringDb.cc
@@ -63,13 +63,21 @@ using namespace std;
 DatedStringDb::DatedStringDb(const char *dbhome, const char *storename)
 {
 #if DB_VERSION_MAJOR >= 3
+#if DB_VERSION_MAJOR >= 5
+  env = new DbEnv((u_int32_t) 0);
+#else
   env = new DbEnv(0);
+#endif
   env->set_error_stream(&cerr);
   env->set_errpfx(storename ? storename : "DatedStringDb");
   env->set_cachesize(0, MPOOL_SIZE, 0);
   env->open(dbhome, DB_CREATE|DB_INIT_MPOOL|DB_PRIVATE, 0644);
   db = new Db(env, 0);
+#if DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1 || DB_VERSION_MAJOR > 4
+  db->open(NULL, storename, NULL, DB_BTREE, DB_CREATE, 0644);
+#else
   db->open(storename, NULL, DB_BTREE, DB_CREATE, 0644);
+#endif
 #elif DB_VERSION_MAJOR == 2
   env = new DbEnv;
   env->set_error_stream(&cerr);
