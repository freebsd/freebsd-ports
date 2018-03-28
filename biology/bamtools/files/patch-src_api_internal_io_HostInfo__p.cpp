--- src/api/internal/io/HostInfo_p.cpp.orig	2015-06-16 16:50:53 UTC
+++ src/api/internal/io/HostInfo_p.cpp
@@ -11,6 +11,8 @@
 using namespace BamTools;
 using namespace BamTools::Internal;
 
+#include <netinet/in.h>
+
 // platorm-specifics
 #ifdef _WIN32
 #  include "api/internal/io/NetWin_p.h"
