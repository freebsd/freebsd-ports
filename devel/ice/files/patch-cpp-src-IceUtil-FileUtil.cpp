--- cpp.orig/src/IceUtil/FileUtil.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceUtil/FileUtil.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -26,6 +26,10 @@
 #  include <dir.h>
 #endif
 
+#ifdef __FreeBSD__
+#  include <unistd.h>
+#endif
+
 using namespace std;
 
 //
