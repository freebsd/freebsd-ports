--- block/dollarindex.cc.orig	2013-06-23 18:13:49 UTC
+++ block/dollarindex.cc
@@ -6,7 +6,7 @@ void Block::dollarIndex(size_t lineNr, s
 {
     d_atDollar.push_back(
         AtDollar(AtDollar::DOLLAR, length(), lineNr, 
-                 text, stol(text.substr(1)), member)
+                 text, A2x(text.substr(1)), member)
     );
     append(text);
 }
