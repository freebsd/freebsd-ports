--- subversion/bindings/javahl/native/JNIUtil.cpp.orig
+++ subversion/bindings/javahl/native/JNIUtil.cpp
@@ -48,6 +48,7 @@
 #include "svn_pools.h"
 #include "svn_error.h"
 #include "svn_fs.h"
+#include "svn_nls.h"
 #include "svn_ra.h"
 #include "svn_utf.h"
 #include "svn_wc.h"
@@ -238,7 +239,7 @@
     svn_pool_destroy(pool);
   }
 #else
-  bindtextdomain(PACKAGE_NAME, SVN_LOCALE_DIR);
+  svn_error_clear(svn_nls_init());
 #endif
 #endif
