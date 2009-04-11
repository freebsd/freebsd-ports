--- DependentExtensions/PostgreSQLInterface/PostgreSQLInterface.cpp.orig	2009-03-26 13:39:35.184163908 +0000
+++ DependentExtensions/PostgreSQLInterface/PostgreSQLInterface.cpp	2009-03-26 13:39:46.373938586 +0000
@@ -27,6 +27,10 @@
 #include "FormatString.h"
 #include "LinuxStrings.h"
 
+#if defined ( __FreeBSD__ )
+#include <stdarg.h>
+#endif
+
 #define PQEXECPARAM_FORMAT_TEXT		0
 #define PQEXECPARAM_FORMAT_BINARY	1
 
