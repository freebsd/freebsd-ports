--- ./src/lib/db/sqlite/sqlitedataset.cpp.orig	Fri Feb 27 22:53:21 2004
+++ ./src/lib/db/sqlite/sqlitedataset.cpp	Thu Mar 25 10:33:48 2004
@@ -33,6 +33,9 @@
 #include <time.h>
 #include <iostream>
 #include <string.h>
+#if defined(__FreeBSD__)
+#  include <publib.h>
+#endif
 
 #include "sqlitedataset.h"
 #include <unistd.h>
