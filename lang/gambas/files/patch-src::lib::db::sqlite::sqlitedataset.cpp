--- src/lib/db/sqlite/sqlitedataset.cpp.orig	Sat Nov 20 13:52:09 2004
+++ src/lib/db/sqlite/sqlitedataset.cpp	Sun Nov 21 21:14:37 2004
@@ -34,6 +34,9 @@
 #include <iostream>
 #include <string.h>
 #include <math.h>
+#if defined(__FreeBSD__)
+#  include <publib.h>
+#endif
 
 #include "sqlitedataset.h"
 #include <unistd.h>
