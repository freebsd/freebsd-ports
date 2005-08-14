--- src/include/common/utils.h.orig	Mon Jan 17 07:29:40 2005
+++ src/include/common/utils.h	Thu Aug 11 20:24:45 2005
@@ -30,6 +30,9 @@
 #include <sstream>
 #include <cassert>
 
+#include <locale.h>
+#include <stdio.h>
+
 #include "platform.h"
 
 #ifdef __WXMSW__
