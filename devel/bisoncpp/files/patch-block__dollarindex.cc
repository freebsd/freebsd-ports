--- ./block/dollarindex.cc.orig	2013-06-23 20:13:49.000000000 +0200
+++ ./block/dollarindex.cc	2013-11-27 18:55:17.000000000 +0100
@@ -6,7 +6,7 @@
 {
     d_atDollar.push_back(
         AtDollar(AtDollar::DOLLAR, length(), lineNr, 
-                 text, stol(text.substr(1)), member)
+                 text, A2x(text.substr(1)), member)
     );
     append(text);
 }
