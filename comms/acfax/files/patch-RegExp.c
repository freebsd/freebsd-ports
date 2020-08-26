--- RegExp.c.orig	1995-07-08 18:20:49 UTC
+++ RegExp.c
@@ -23,7 +23,6 @@
  */ 
 
 #include "RegExp.h"
-#include <regex.h>
 
 void RegExpCompile(regexp,fsm_ptr)
 char *regexp;
