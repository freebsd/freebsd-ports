--- pcrecpp.cc.orig	Wed Jun 22 12:40:52 2005
+++ pcrecpp.cc	Wed Jul 27 17:14:34 2005
@@ -36,6 +36,7 @@
 #include <assert.h>
 #include <errno.h>
 #include <string>
+#include <algorithm>
 #include "config.h"
 // We need this to compile the proper dll on windows/msys.  This is copied
 // from pcre_internal.h.  It would probably be better just to include that.
@@ -378,7 +379,7 @@
   int matches = TryMatch(text, 0, UNANCHORED, vec, kVecSize);
   if (matches == 0)
     return false;
-  out->clear();
+  out->erase();
   return Rewrite(out, rewrite, text, vec, matches);
 }
 
