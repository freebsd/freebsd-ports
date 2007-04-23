--- extconf.rb.orig	Mon Sep 11 14:01:18 2006
+++ extconf.rb	Mon Oct 16 09:57:09 2006
@@ -9,6 +9,7 @@
     header = cpp_include(header)
     if try_compile(<<"SRC", opt, &b)
 #{COMMON_HEADERS}
+#include <sys/types.h>
 #{header}
 /*top*/
 int
