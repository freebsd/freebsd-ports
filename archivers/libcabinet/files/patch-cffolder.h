--- cffolder.h.orig	1999-10-24 06:13:29 UTC
+++ cffolder.h
@@ -15,7 +15,7 @@
 #define __CFFOLDER_H__
 
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 #include "cftypes.h"
 #include "cfheader.h"
 
@@ -89,4 +89,5 @@ class cabinet_folder_header : public cab
 
 ////////////////////////////////////////////////////////////////////////////////
 
-#endif
\ No newline at end of file
+#endif
+
