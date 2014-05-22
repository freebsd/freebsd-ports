--- /dev/null	1970-01-01 01:00:00.000000000 +0100
+++ config.m4	2014-04-28 15:50:27.000000000 +0200
@@ -0,0 +1,14 @@
+dnl Copyright (C) 2009 Facebook
+dnl Copying and distribution of this file, with or without modification,
+dnl are permitted in any medium without royalty provided the copyright
+dnl notice and this notice are preserved.
+
+PHP_ARG_ENABLE(thrift_protocol, whether to enable the thrift_protocol extension,
+[  --enable-thrift_protocol	Enable the fbthrift_protocol extension])
+
+if test "$PHP_THRIFT_PROTOCOL" != "no"; then
+  PHP_REQUIRE_CXX()
+  PHP_ADD_LIBRARY_WITH_PATH(stdc++, "", THRIFT_PROTOCOL_SHARED_LIBADD)
+  PHP_SUBST(THRIFT_PROTOCOL_SHARED_LIBADD)
+  PHP_NEW_EXTENSION(thrift_protocol, php_thrift_protocol.cpp, $ext_shared)
+fi
