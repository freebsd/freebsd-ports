--- lashd/server.c.orig	Sat Jan 13 15:23:38 2007
+++ lashd/server.c	Sat Jan 13 15:23:47 2007
@@ -25,6 +25,7 @@
 #include <signal.h>
 #include <assert.h>
 #include <uuid/uuid.h>
+#include <unistd.h>
 
 #include <lash/loader.h>
 #include <lash/internal_headers.h>
