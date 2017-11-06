--- plugin/password_validation/validate_password.cc.orig	2013-09-10 07:38:25.000000000 +0000
+++ plugin/password_validation/validate_password.cc	2013-10-05 15:40:20.790380179 +0000
@@ -16,6 +16,8 @@
 #include <my_sys.h>
 #include <string>
 #include <mysql/plugin_validate_password.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <set>
 #include <iostream>
 #include <fstream>
