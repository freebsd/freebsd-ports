--- extra/kipi-plugins/common/libkipiplugins/tools/kpversion.cpp.orig	2018-06-16 09:09:44 UTC
+++ extra/kipi-plugins/common/libkipiplugins/tools/kpversion.cpp
@@ -21,7 +21,7 @@
  * ============================================================ */
 
 #include "kpversion.h"
-#include "gitversion.h"
+#define GITVERSION ""
 
 namespace pluginsVersion {
 
