--- source/tools/groupfile.cpp.orig	Sat Oct 30 21:00:02 2004
+++ source/tools/groupfile.cpp	Sat Oct 30 21:14:57 2004
@@ -15,6 +15,7 @@
  *                                                                         *
  ***************************************************************************/
 #include "groupfile.h"
+#include <algorithm>
 
 
 bool lessCat(AbstractEntry const * a, AbstractEntry const * b) {
