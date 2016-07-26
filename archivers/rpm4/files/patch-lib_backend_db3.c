--- lib/backend/db3.c.orig	2014-06-30 08:47:13 UTC
+++ lib/backend/db3.c
@@ -8,6 +8,8 @@ static int _debug = 1;	/* XXX if < 0 deb
 
 #include <errno.h>
 #include <sys/wait.h>
+#include <sys/types.h>
+#include <signal.h>
 #include <db.h>
 
 #include <rpm/rpmtypes.h>
