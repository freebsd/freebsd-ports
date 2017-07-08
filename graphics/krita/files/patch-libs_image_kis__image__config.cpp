--- libs/image/kis_image_config.cpp.orig	2016-09-06 07:12:46 UTC
+++ libs/image/kis_image_config.cpp
@@ -39,6 +39,11 @@
 #include <errno.h>
 #endif
 
+#ifdef Q_OS_FREEBSD
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 KisImageConfig::KisImageConfig(bool readOnly)
     : m_config( KSharedConfig::openConfig()->group("")),
       m_readOnly(readOnly)
