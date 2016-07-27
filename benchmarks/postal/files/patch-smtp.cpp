--- smtp.cpp.orig	2012-01-14 12:38:45 UTC
+++ smtp.cpp
@@ -8,6 +8,7 @@
 #include "userlist.h"
 #include "logit.h"
 #include "results.h"
+#include <cstdlib>
 #include <cstring>
 
 smtpData::smtpData()
