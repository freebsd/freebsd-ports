--- assa/Logger_Impl.h.orig	Mon Oct 13 11:30:18 2003
+++ assa/Logger_Impl.h	Thu Jan 29 00:28:19 2004
@@ -16,6 +16,8 @@
 
 #include <errno.h>
 #include <string>
+#include <stdarg.h>
+#include <sys/types.h>
 
 using std::string;
 using std::ostream;
