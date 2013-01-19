--- regex_cs.c.orig	Tue Feb  7 12:08:50 2006
+++ regex_cs.c	Tue Feb  7 12:10:03 2006
@@ -39,7 +39,7 @@
 #include "config.h"
 #endif
 #include "defines.h"
-#include "multi.h"
+#include "less.h"
 #define ISCSDMY(c,cs)           (CSISASCII(cs) && (c == PADCH))
 
 #define SWITCH_ENUM_BUG
