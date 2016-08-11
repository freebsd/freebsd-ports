--- thirdparty/qzip/qzip.cpp.orig	2015-07-16 21:02:34 UTC
+++ thirdparty/qzip/qzip.cpp
@@ -45,6 +45,9 @@
 #include "qzipreader_p.h"
 #include "qzipwriter_p.h"
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 #include <zlib.h>
 
 #if defined(Q_OS_WIN) or defined(Q_OS_ANDROID)
