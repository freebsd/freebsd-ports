$FreeBSD$

--- RegExp.c.old	Sun Feb 10 05:33:07 2002
+++ RegExp.c	Sun Feb 10 05:33:24 2002
@@ -23,7 +23,6 @@
  */ 
 
 #include "RegExp.h"
-#include <regex.h>
 
 void RegExpCompile(regexp,fsm_ptr)
 char *regexp;
