--- test/idiscover.cc.orig	2008-06-25 20:50:26.000000000 +0000
+++ test/idiscover.cc
@@ -2,6 +2,7 @@
 #include <stdexcept>
 #include <iterator>
 #include <algorithm>
+#include <unistd.h>
 using namespace std;
 #include <opkele/exception.h>
 #include <opkele/discovery.h>
