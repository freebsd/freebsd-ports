--- frend.cc.orig	Thu Mar 10 13:43:06 2005
+++ frend.cc	Thu Mar 10 13:44:15 2005
@@ -18,6 +18,7 @@
 #include "frend.h"
 #include <unistd.h>
 #include <sys/stat.h>
+#include <sys/errno.h>
 #include <cstdlib>
 #include <climits>
 #include <sstream>
