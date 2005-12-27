--- rlcodegen/fsmcodegen.cpp.orig	Wed Dec 21 15:15:28 2005
+++ rlcodegen/fsmcodegen.cpp	Mon Dec 26 13:36:08 2005
@@ -25,6 +25,7 @@
 #include "fsmcodegen.h"
 #include "redfsm.h"
 #include "gendata.h"
+#include <climits>
 #include <sstream>
 
 /* Determine if a string is only whitespace. Code blocks that are only
