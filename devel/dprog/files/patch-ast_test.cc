--- ast_test.cc.orig	Mon Apr 12 11:22:05 2004
+++ ast_test.cc	Mon Apr 12 11:22:15 2004
@@ -3,6 +3,7 @@
 #include "visitor.hh"
 using namespace ast;
 
+#include <cstdio>
 #include <iostream>
 
 int yyparse();
