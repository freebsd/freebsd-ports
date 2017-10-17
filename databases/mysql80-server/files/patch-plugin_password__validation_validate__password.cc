--- plugin/password_validation/validate_password.cc.orig	2017-06-27 11:44:29 UTC
+++ plugin/password_validation/validate_password.cc
@@ -17,6 +17,8 @@
 #include <mysql/plugin_validate_password.h>
 #include <mysql/service_my_plugin_log.h>
 #include <mysql/service_mysql_string.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
