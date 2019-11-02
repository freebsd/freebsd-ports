--- plugin/password_validation/validate_password.cc.orig	2019-10-21 05:21:41 UTC
+++ plugin/password_validation/validate_password.cc
@@ -25,6 +25,8 @@
 #include <mysql/plugin_validate_password.h>
 #include <mysql/service_my_plugin_log.h>
 #include <mysql/service_mysql_string.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <set>
 #include <iostream>
 #include <fstream>
