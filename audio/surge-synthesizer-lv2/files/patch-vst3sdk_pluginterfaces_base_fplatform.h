--- vst3sdk/pluginterfaces/base/fplatform.h.orig	2020-04-15 17:42:41 UTC
+++ vst3sdk/pluginterfaces/base/fplatform.h
@@ -76,14 +76,14 @@
 	#endif		
 //-----------------------------------------------------------------------------
 // LINUX
-#elif __gnu_linux__
+#elif __gnu_linux__ || defined(__FreeBSD__) || defined(__DragonFly__)
 	#define SMTG_OS_LINUX	1
 	#define SMTG_OS_MACOS	0
 	#define SMTG_OS_WINDOWS	0
 	#define SMTG_OS_IOS		0
 	#define SMTG_OS_OSX		0
 
-	#include <endian.h>
+	#include <sys/endian.h>
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
 		#define BYTEORDER kLittleEndian
 	#else
