
$FreeBSD$

--- backends/bdb.h	2001/06/05 14:10:55	1.1
+++ backends/bdb.h	2001/06/05 14:11:10
@@ -116,7 +116,7 @@
 
 #ifndef BDB_H
 
-#include <db.h>
+#include <db3/db.h>
 #include <glib.h>
 #include <gconf/gconf.h>
 
