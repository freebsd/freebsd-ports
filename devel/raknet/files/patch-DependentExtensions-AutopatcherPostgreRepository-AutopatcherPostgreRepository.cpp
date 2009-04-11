--- DependentExtensions/AutopatcherPostgreRepository/AutopatcherPostgreRepository.cpp.orig	2009-03-26 13:49:16.239379864 +0000
+++ DependentExtensions/AutopatcherPostgreRepository/AutopatcherPostgreRepository.cpp	2009-03-26 13:49:45.234791013 +0000
@@ -43,6 +43,10 @@
 //#include <stdlib.h>
 #endif
 
+#if defined ( __FreeBSD__ )
+#include <assert.h>
+#endif
+
 #define PQEXECPARAM_FORMAT_TEXT		0
 #define PQEXECPARAM_FORMAT_BINARY	1
 
