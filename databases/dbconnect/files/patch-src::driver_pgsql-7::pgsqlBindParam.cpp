--- src/driver_pgsql-7/pgsqlBindParam.cpp.orig	Sat Mar  6 03:47:23 2004
+++ src/driver_pgsql-7/pgsqlBindParam.cpp	Sat Mar  6 03:47:41 2004
@@ -18,7 +18,7 @@
  *
  */
 
-
+#include <stdio.h>
 #include "pgsqlBindParam.h"
 #include "dbconnectTypes.h"
