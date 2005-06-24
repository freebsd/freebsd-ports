--- common/error.cc.orig	Fri Jun 24 08:58:42 2005
+++ common/error.cc	Fri Jun 24 08:59:00 2005
@@ -23,6 +23,7 @@
 #include <ac/assert.h>
 #include <ac/ctype.h>
 #include <ac/errno.h>
+#include <sys/types.h>
 #include <ac/grp.h>
 #include <ac/pwd.h>
 #include <ac/stdarg.h>
