--- src/applog.cpp	2010-10-31 16:11:55.000000000 -0700
+++ src/applog.cpp	2012-08-12 20:50:40.000000000 -0700
@@ -45,6 +45,7 @@
 #include <cstdlib>
 #include <stdarg.h>
 #include <errno.h>
+#include <sys/stat.h>
 
 // TODO sc: test if has to move up now that it is into commoncpp
 // NOTE: the order of inclusion is important do not move following include line
@@ -53,6 +54,8 @@
 // local includes
 #include <cc++/applog.h>
 
+using namespace std;
+
 #ifdef  CCXX_NAMESPACES
 using namespace std;
 namespace ost
