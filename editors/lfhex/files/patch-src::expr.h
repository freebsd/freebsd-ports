--- src/expr.h.orig	Fri Feb 13 13:28:39 2004
+++ src/expr.h	Mon Apr 26 20:56:45 2004
@@ -11,6 +11,7 @@
  *                                                                      
  *----------------------------------------------------------------------*/
 #include <string>
+#include <sys/types.h>
 
 bool expr_eval( const std::string &str, off_t &value );
 
