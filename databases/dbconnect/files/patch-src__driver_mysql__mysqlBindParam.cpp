--- src/driver_mysql/mysqlBindParam.cpp.orig	Sat Mar  6 03:45:41 2004
+++ src/driver_mysql/mysqlBindParam.cpp	Sat Mar  6 03:45:59 2004
@@ -18,7 +18,7 @@
  *
  */
 
-
+#include <stdio.h>
 #include "mysqlBindParam.h"
 #include "dbconnectTypes.h"
