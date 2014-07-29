--- dns-terror/DatedStringDb.cc.orig	Sat Sep  6 18:38:24 2003
+++ dns-terror/DatedStringDb.cc	Sat Sep  6 18:38:31 2003
@@ -69,7 +69,11 @@
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
