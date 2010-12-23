--- include/zrtp.h.orig	2009-03-22 06:26:34.000000000 -0700
+++ include/zrtp.h	2010-12-01 14:29:40.886762007 -0800
@@ -14,6 +14,8 @@
 #ifndef __ZRTP_H__
 #define __ZRTP_H__
 
+#include "zrtp_config_unix.h"
+
 #include "zrtp_config.h"
 #include "zrtp_base.h"
 #include "zrtp_error.h"
