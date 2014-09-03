--- ./src/Mixfix/interact.cc.orig	2014-09-03 02:53:35.000000000 +0200
+++ ./src/Mixfix/interact.cc	2014-09-03 02:54:14.000000000 +0200
@@ -25,13 +25,14 @@
 //
 #include <signal.h>
 
+#include "surface.h"
+
 bool UserLevelRewritingContext::interactiveFlag = true;
 bool UserLevelRewritingContext::ctrlC_Flag = false;
 bool UserLevelRewritingContext::stepFlag = false;
 bool UserLevelRewritingContext::abortFlag = false;
 int UserLevelRewritingContext::debugLevel = 0;
 
-int yyparse(void*);
 void cleanUpParser();
 void cleanUpLexer();
 
