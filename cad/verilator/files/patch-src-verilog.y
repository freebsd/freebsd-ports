--- src/verilog.y.orig	2020-02-08 14:14:33 UTC
+++ src/verilog.y
@@ -20,6 +20,7 @@
 // Original code here by Paul Wasson and Duane Galbi
 //*************************************************************************
 
+%define parse.error verbose
 %{
 #include "V3Ast.h"
 #include "V3Global.h"
@@ -29,7 +30,6 @@
 #include <cstdlib>
 #include <cstdarg>
 
-#define YYERROR_VERBOSE 1
 #define YYINITDEPTH 10000	// Older bisons ignore YYMAXDEPTH
 #define YYMAXDEPTH 10000
 
