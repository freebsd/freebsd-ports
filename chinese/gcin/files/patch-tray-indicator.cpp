--- tray-indicator.cpp.orig	2016-10-20 17:07:12 UTC
+++ tray-indicator.cpp
@@ -1,3 +1,4 @@
+#if USE_INDICATOR
 #include "gcin.h"
 #include "pho.h"
 #include "gtab.h"
@@ -300,3 +301,4 @@ void destroy_tray_indicator()
   g_object_unref(indicator_state);  indicator_state = NULL;
 #endif  
 }
+#endif
