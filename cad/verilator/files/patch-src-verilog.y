--- src/verilog.y.orig	2020-07-11 01:58:03 UTC
+++ src/verilog.y
@@ -17,6 +17,7 @@
 //*************************************************************************
 // clang-format off
 
+%define parse.error verbose
 %{
 #ifdef NEVER_JUST_FOR_CLANG_FORMAT
  }
@@ -31,7 +32,6 @@
 #include <cstdarg>
 #include <stack>
 
-#define YYERROR_VERBOSE 1  // For prior to Bison 3.6
 #define YYINITDEPTH 10000  // Older bisons ignore YYMAXDEPTH
 #define YYMAXDEPTH 10000
 
