--- libs/vst3/pluginterfaces/base/fplatform.h.orig	2023-10-10 20:07:54 UTC
+++ libs/vst3/pluginterfaces/base/fplatform.h
@@ -86,7 +86,7 @@
 //-----------------------------------------------------------------------------
 // LINUX
 //-----------------------------------------------------------------------------
-#elif __gnu_linux__ || __linux__
+#elif __gnu_linux__ || __linux__ || __FreeBSD__
 	#define SMTG_OS_LINUX	1
 	#define SMTG_OS_MACOS	0
 	#define SMTG_OS_WINDOWS	0
