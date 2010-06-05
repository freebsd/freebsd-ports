--- ./parser/parser.h.orig	2010-03-31 14:28:49.000000000 +0200
+++ ./parser/parser.h	2010-06-05 01:02:00.913097223 +0200
@@ -155,7 +155,7 @@
         void multiplyDefined(Symbol const *sp);
 
         void nestedBlock(Block &block); // define inner block as pseudo N
-        std::string *newYYText() const; // make dynamic copy of YYText()
+        std::string *newYYText(); // make dynamic copy of YYText()
 
         std::string nextHiddenName();
         void noDefaultTypeWarning();
@@ -406,7 +406,7 @@
 {
     return d_stackDecl;
 }
-inline std::string *Parser::newYYText() const
+inline std::string *Parser::newYYText()
 {
     return new std::string(d_scanner.YYText());
 }
