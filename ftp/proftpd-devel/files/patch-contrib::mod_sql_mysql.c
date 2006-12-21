--- contrib/mod_sql_mysql.c.orig	Tue Dec 12 19:52:15 2006
+++ contrib/mod_sql_mysql.c	Tue Dec 12 20:02:56 2006
@@ -135,7 +135,7 @@
 #include "conf.h"
 #include "../contrib/mod_sql.h"
 
-#include <mysql.h>
+#include <mysql/mysql.h>
 
 /* 
  * timer-handling code adds the need for a couple of forward declarations
