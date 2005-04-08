--- extensions/psql/interface.c.orig	Tue Mar  1 21:47:06 2005
+++ extensions/psql/interface.c	Tue Mar  1 22:08:58 2005
@@ -24,7 +24,7 @@
 #define PTS_MODULE "pgsqlinterf.c"
 
 /* vvv Debian GNU/Linux: /usr/include/postgresql/libpq-fe.h */
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #include "../../basext.h"
 #include <stdio.h> /* simple debugging */
 #include <string.h> /* memcmp() */
