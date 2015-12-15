--- plugin/password_validation/validate_password.cc.orig	2015-11-29 19:16:24 UTC
+++ plugin/password_validation/validate_password.cc
@@ -18,6 +18,8 @@
 #include <mysql/plugin_validate_password.h>
 #include <mysql/service_my_plugin_log.h>
 #include <mysql/service_mysql_string.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <set>
 #include <iostream>
 #include <fstream>
