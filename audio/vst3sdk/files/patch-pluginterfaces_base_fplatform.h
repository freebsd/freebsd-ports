--- pluginterfaces/base/fplatform.h.orig	2021-12-16 12:29:35 UTC
+++ pluginterfaces/base/fplatform.h
@@ -114,7 +114,7 @@
 //-----------------------------------------------------------------------------
 // LINUX
 //-----------------------------------------------------------------------------
-#elif __gnu_linux__ || __linux__
+#elif __gnu_linux__ || __linux__ || defined(__FreeBSD__)
 	#define SMTG_OS_LINUX	1
 	#define SMTG_OS_MACOS	0
 	#define SMTG_OS_WINDOWS	0
@@ -127,7 +127,7 @@
 	#define SMTG_CPU_ARM_64	__aarch64__
 	#define SMTG_CPU_ARM_64EC 0
 
-	#include <endian.h>
+	#include <sys/endian.h>
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
 		#define BYTEORDER kLittleEndian
 	#else
