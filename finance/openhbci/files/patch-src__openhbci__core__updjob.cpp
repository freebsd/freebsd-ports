--- src/openhbci/core/updjob.cpp.orig	2003-01-31 22:13:29.000000000 +0300
+++ src/openhbci/core/updjob.cpp	2014-07-03 13:52:04.000000000 +0400
@@ -43,6 +43,7 @@
 
 #include "updjob.h"
 #include "hbcistring.h"
+#include <stdlib.h> // for atoi()
 
 
 namespace HBCI {
