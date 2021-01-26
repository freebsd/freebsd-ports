--- src/verilog.y.orig	2020-08-14 11:38:09 UTC
+++ src/verilog.y
@@ -31,7 +31,6 @@
 #include <cstdarg>
 #include <stack>
 
-#define YYERROR_VERBOSE 1  // For prior to Bison 3.6
 #define YYINITDEPTH 10000  // Older bisons ignore YYMAXDEPTH
 #define YYMAXDEPTH 10000
 
