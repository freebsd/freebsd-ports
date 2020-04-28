--- storage/innobase/handler/i_s.cc.orig	2020-03-09 10:37:59 UTC
+++ storage/innobase/handler/i_s.cc
@@ -43,6 +43,10 @@ Created July 18, 2007 Vasil Dimov
 #include <sql_plugin.h>
 #include <mysql/innodb_priv.h>
 
+#include <string>
+#include <sstream>
+#include <iostream>
+
 #include "btr0pcur.h"
 #include "btr0types.h"
 #include "dict0dict.h"
