--- plugin/password_validation/validate_password.cc.orig	2019-10-21 05:17:49 UTC
+++ plugin/password_validation/validate_password.cc
@@ -23,6 +23,8 @@
 #include <my_sys.h>
 #include <string>
 #include <mysql/plugin_validate_password.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <set>
 #include <ios>       // std::streamoff
 #include <iostream>
