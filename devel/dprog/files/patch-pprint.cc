--- pprint.cc.orig	Mon Apr 12 11:20:27 2004
+++ pprint.cc	Mon Apr 12 11:20:46 2004
@@ -3,6 +3,7 @@
 using namespace ast;
 #include "pretty_printer.hh"
 
+#include <cstdio>
 #include <iostream>
 
 int yyparse();
