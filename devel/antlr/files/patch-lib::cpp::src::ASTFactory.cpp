$FreeBSD$

--- lib/cpp/src/ASTFactory.cpp.orig	Mon Nov 15 16:31:34 2004
+++ lib/cpp/src/ASTFactory.cpp	Mon Nov 15 16:32:20 2004
@@ -12,7 +12,11 @@
 #include "antlr/ANTLRUtil.hpp"
 
 #include <iostream>
+#if defined(__GNUC__) && (__GNUC__ < 3 || __GNUC_MINOR__ < 2)
+#include <istream.h>
+#else
 #include <istream>
+#endif
 
 using namespace std;
 
