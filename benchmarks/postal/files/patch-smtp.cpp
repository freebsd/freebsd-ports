--- smtp.cpp.orig
+++ smtp.cpp
@@ -8,6 +8,7 @@
 #include "userlist.h"
 #include "logit.h"
 #include "results.h"
+#include <cstdlib>
 #include <cstring>
 
 smtpData::smtpData()
