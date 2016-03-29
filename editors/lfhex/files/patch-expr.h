--- expr.h.orig	2008-09-19 00:36:49 UTC
+++ expr.h
@@ -19,6 +19,7 @@
  */
 
 #include <string>
+#include <sys/types.h>
 
 bool expr_eval( const std::string &str, off_t &value );
 
