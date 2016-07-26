--- cffile.h.orig	1999-10-24 06:13:29 UTC
+++ cffile.h
@@ -15,7 +15,7 @@
 #define __CFFILE_H__
 
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 #include "bstring.h"
 #include "cftypes.h"
 
@@ -161,4 +161,4 @@ class cabinet_file_header : public cabin
 
 ////////////////////////////////////////////////////////////////////////////////
 
-#endif
\ No newline at end of file
+#endif
