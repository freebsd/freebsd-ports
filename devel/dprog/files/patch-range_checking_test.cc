--- range_checking_test.cc.orig	Tue Apr  6 09:01:30 2004
+++ range_checking_test.cc	Tue Apr  6 09:01:43 2004
@@ -4,6 +4,8 @@
 #include "ast.hh"
 #include <iostream>
 
+#include <cassert>
+
 int yyparse();
 
 ast::DProg *dprog = 0;
