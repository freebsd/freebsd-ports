--- lib/cpp/antlr/ANTLRException.hpp.orig	Fri Apr 25 01:59:50 2003
+++ lib/cpp/antlr/ANTLRException.hpp	Fri Apr 25 01:55:50 2003
@@ -9,6 +9,7 @@
  */
 
 #include <antlr/config.hpp>
+#include <exception>
 #include <string>
 
 #ifdef ANTLR_CXX_SUPPORTS_NAMESPACE
