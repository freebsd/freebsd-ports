--- lib/backend/db3.c.orig	2011-03-02 07:40:10.000000000 +0100
+++ lib/backend/db3.c	2011-06-10 15:21:12.000000000 +0200
@@ -8,6 +8,8 @@ static int _debug = 1;	/* XXX if < 0 deb
 
 #include <errno.h>
 #include <sys/wait.h>
+#include <sys/types.h>
+#include <signal.h>
 
 #include <rpm/rpmtypes.h>
 #include <rpm/rpmmacro.h>
@@ -213,7 +215,7 @@ errxit:
 
 void dbSetFSync(void *dbenv, int enable)
 {
-    db_env_set_func_fsync(enable ? fdatasync : fsync_disable);
+    db_env_set_func_fsync(enable ? fsync : fsync_disable);
 }
 
 int dbiSync(dbiIndex dbi, unsigned int flags)
