--- src/sql/drivers/ibase/qsql_ibase.cpp.orig	Sun Apr  4 08:13:00 2004
+++ src/sql/drivers/ibase/qsql_ibase.cpp	Sun Apr  4 08:13:16 2004
@@ -18,7 +18,7 @@
 #include <private/qsqlextension_p.h>
 
 #include <ibase.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <limits.h>
 #include <math.h>
 
