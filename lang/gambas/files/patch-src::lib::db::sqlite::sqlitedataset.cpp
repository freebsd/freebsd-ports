--- src/lib/db/sqlite/sqlitedataset.cpp.orig	Fri Feb 27 22:53:21 2004
+++ src/lib/db/sqlite/sqlitedataset.cpp	Sun May 16 14:58:59 2004
@@ -33,6 +33,9 @@
 #include <time.h>
 #include <iostream>
 #include <string.h>
+#if defined(__FreeBSD__)
+#  include <publib.h>
+#endif
 
 #include "sqlitedataset.h"
 #include <unistd.h>
@@ -148,7 +151,11 @@
 			    break; 
 		       case ft_Float:
 	 		    v.set_asString(reslt[i]);
+#if defined(__FreeBSD__) && !defined(_GLIBCPP_HAVE_STRTOF)
+	 		    v.set_asFloat((float)strtod(reslt[i], NULL));
+#else
 	 		    v.set_asFloat(strtof(reslt[i], NULL));
+#endif
 			    break; 
 		       case ft_Double:
 	 		    v.set_asString(reslt[i]);
