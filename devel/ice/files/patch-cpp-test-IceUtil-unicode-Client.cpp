--- cpp.orig/test/IceUtil/unicode/Client.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/test/IceUtil/unicode/Client.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -15,6 +15,10 @@
 #   include <io.h>
 #endif
 
+#ifdef __FreeBSD__
+#   include <unistd.h>
+#endif
+
 using namespace IceUtil;
 using namespace std;
 
