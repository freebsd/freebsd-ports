--- core/app/utils/digikam_version.cpp.orig	2019-11-03 09:03:59 UTC
+++ core/app/utils/digikam_version.cpp
@@ -29,7 +29,7 @@
 
 // Local includes.
 
-#include "gitversion.h"
+#define GITVERSION ""
 #include "daboutdata.h"
 
 #if defined(Q_CC_GNU)
