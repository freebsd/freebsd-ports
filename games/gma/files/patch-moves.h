--- src/moves.h.orig
+++ src/moves.h
@@ -24,7 +24,9 @@
 
 #include "pattern.h"
 
-#include <stl.h>
+#include <map>
+
+using std::map;
 
 class Moves:map<Pattern,int>
 {
