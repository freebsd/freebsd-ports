--- async/parseopt.C.orig	2005-11-01 16:20:32.000000000 +0000
+++ async/parseopt.C	2007-07-12 22:38:53.000000000 +0000
@@ -24,7 +24,7 @@
 #include "amisc.h"
 #include "parseopt.h"
 
-char *parseargs::errorbuf = "";
+char *parseargs::errorbuf = (char *)"";
 
 static inline int
 isspc (char c)
