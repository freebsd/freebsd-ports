diff -Naurp src/match.c src/match.c
--- src/match.c	2007-02-26 12:26:10.000000000 +0000
+++ src/match.c	2007-02-26 12:26:17.000000000 +0000
@@ -36,6 +36,7 @@
 /* Remove the next line to use this in IrcII */
 #define EGGDROP
 
+#include <p_global.h>
 
 /* ===================================================================
  * Best to leave stuff after this point alone, but go on and change
