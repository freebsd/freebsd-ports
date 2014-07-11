--- src/openhbci/core/date.cpp.orig	2003-04-25 05:45:54.000000000 +0400
+++ src/openhbci/core/date.cpp	2014-07-03 13:48:43.000000000 +0400
@@ -43,6 +43,8 @@
 #include "date.h"
 #include "hbcistring.h"
 
+#include <stdlib.h> // for atoi()
+
 
 namespace HBCI {
 
