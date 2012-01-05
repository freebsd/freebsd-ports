--- mysac_decode_field.c.orig	2011-06-06 20:58:33.000000000 +0100
+++ mysac_decode_field.c	2012-01-02 05:47:37.837388605 +0000
@@ -21,8 +21,8 @@
 #include <stdint.h>
 #include <string.h>
 #include <stdarg.h>
-#include <mysql/mysql.h>
 #include <mysql/my_global.h>
+#include <mysql/mysql.h>
 
 #include "mysac_utils.h"
 #include "mysac.h"
