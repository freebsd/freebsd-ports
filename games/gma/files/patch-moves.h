--- src/moves.h.orig	Sun May 18 19:18:04 2003
+++ src/moves.h	Sun May 18 19:18:19 2003
@@ -24,7 +24,7 @@
 
 #include "pattern.h"
 
-#include <stl.h>
+#include <map.h>
 
 class Moves:map<Pattern,int>
 {
