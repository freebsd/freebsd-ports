--- plugins/org.eclipse.swt/Eclipse SWT Mozilla/common/library/xpcom_profile.h.orig	Wed Nov 29 12:08:43 2006
+++ plugins/org.eclipse.swt/Eclipse SWT Mozilla/common/library/xpcom_profile.h	Wed Nov 29 12:09:33 2006
@@ -32,7 +32,7 @@
 #define NDEBUG
 
 #include "nsCOMPtr.h"
-#include "nsProfileDirServiceProvider.h"
+#include "profdirserviceprovider/nsProfileDirServiceProvider.h"
 #include "xpcom_stats.h"
 
 #endif /* INC_xpcom_profile_H */
