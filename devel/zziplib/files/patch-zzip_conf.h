--- zzip/conf.h.orig	Wed Apr 26 08:24:22 2006
+++ zzip/conf.h	Wed Apr 26 08:24:54 2006
@@ -21,6 +21,8 @@
 #ifndef _ZZIP_CONF_H
 #define _ZZIP_CONF_H 1
 
+#include <sys/types.h>
+
 #if !defined ZZIP_OMIT_CONFIG_H
 # if defined _MSC_VER || defined __BORLANDC__ || defined __WATCOMC__
 # include <zzip/_msvc.h>
