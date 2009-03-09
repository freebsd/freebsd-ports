--- parser/parser.h.orig	2007-10-15 11:58:20.000000000 +0200
+++ parser/parser.h	2009-03-05 15:50:45.000000000 +0100
@@ -151,7 +151,7 @@
         void multiplyDefined(Symbol const *sp);
 
         void nestedBlock(Block &block); // define inner block as pseudo N
-        std::string *newYYText() const; // make dynamic copy of YYText()
+        std::string *newYYText(); // make dynamic copy of YYText()
 
         std::string nextHiddenName();
         void noDefaultTypeWarning();
@@ -382,7 +382,7 @@
     return d_stackDecl;
 }
 
-inline std::string *Parser::newYYText() const
+inline std::string *Parser::newYYText()
 {
     return new std::string(d_scanner.YYText());
 }
