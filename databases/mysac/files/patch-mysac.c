--- mysac.c.orig	2012-01-02 05:39:13.267796448 +0000
+++ mysac.c	2012-01-02 05:39:23.079360664 +0000
@@ -22,8 +22,8 @@
 #include <string.h>
 #include <stdarg.h>
 #include <ctype.h>
-#include <mysql/mysql.h>
 #include <mysql/my_global.h>
+#include <mysql/mysql.h>
 
 #include "mysac_decode_field.h"
 #include "mysac_encode_values.h"
