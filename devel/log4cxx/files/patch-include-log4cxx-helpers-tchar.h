--- include/log4cxx/helpers/tchar.h.orig	Wed Jan 12 17:56:51 2005
+++ include/log4cxx/helpers/tchar.h	Wed Jan 12 17:57:04 2005
@@ -83,6 +83,9 @@
 	#include <malloc.h>
 	#define USES_CONVERSION void * _dst = _alloca(1024);
 #endif
+#elif defined( __FreeBSD__ )
+	#include <stdlib.h>
+	#define USES_CONVERSION void * _dst = alloca(1024);
 #else
 	#include <alloca.h>
 	#define USES_CONVERSION void * _dst = alloca(1024);
