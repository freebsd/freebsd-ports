--- plugin/password_validation/validate_password.cc.orig	2025-10-25 22:02:46.860837000 +0200
+++ plugin/password_validation/validate_password.cc	2025-10-25 22:06:50.601189000 +0200
@@ -26,6 +26,8 @@
 #include <mysql/plugin_validate_password.h>
 #include <mysql/service_my_plugin_log.h>
 #include <mysql/service_mysql_string.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <sys/types.h>
 #include <algorithm>  // std::swap
 #include <cstdio>
