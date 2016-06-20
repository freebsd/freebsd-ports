--- src/match.c.orig	2016-06-20 14:41:27 UTC
+++ src/match.c
@@ -36,6 +36,7 @@
 /* Remove the next line to use this in IrcII */
 #define EGGDROP
 
+#include <p_global.h>
 
 /* ===================================================================
  * Best to leave stuff after this point alone, but go on and change
