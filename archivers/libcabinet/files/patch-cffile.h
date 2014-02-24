--- cffile.h.orig	1999-10-24 02:13:29.000000000 -0400
+++ cffile.h	2014-02-21 16:12:05.824389036 -0500
@@ -15,7 +15,7 @@
 #define __CFFILE_H__
 
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 #include "bstring.h"
 #include "cftypes.h"
 
@@ -161,4 +161,4 @@
 
 ////////////////////////////////////////////////////////////////////////////////
 
-#endif
\ No newline at end of file
+#endif
