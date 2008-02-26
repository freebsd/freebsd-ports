--- expr.h.orig	Sun Nov  5 13:26:04 2006
+++ expr.h	Wed Dec 26 02:53:48 2007
@@ -19,6 +19,7 @@
  */
 
 #include <string>
+#include <sys/types.h>
 
 bool expr_eval( const std::string &str, off_t &value );
 
