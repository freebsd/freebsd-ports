--- util/MYODBCUtil.h.orig	Sun Oct  9 22:33:40 2005
+++ util/MYODBCUtil.h	Thu Oct 27 16:13:47 2005
@@ -40,7 +40,11 @@
 #include <sqlext.h>
 #endif
 
+# if defined(HAVE_IODBCINST_H)
+#include <iodbcinst.h>
+#elif defined(HAVE_ODBCINST_H)
 #include <odbcinst.h>
+# endif
 
 /* 
     Handle case on OSX where we want to use GetPrivateProfileString (because it 
