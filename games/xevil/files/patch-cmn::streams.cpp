--- cmn/streams.cpp.orig	Wed Jan 19 12:54:32 2000
+++ cmn/streams.cpp	Sat Oct 25 21:44:08 2003
@@ -31,7 +31,8 @@
 #include "utils.h"
 #include "neth.h" // needed for recv, send, recvfrom, sendto
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "streams.h"
 #include "xetp.h" // yuck, need this for XETP::versionStr
