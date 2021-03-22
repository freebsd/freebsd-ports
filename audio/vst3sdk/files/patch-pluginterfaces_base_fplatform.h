--- pluginterfaces/base/fplatform.h.orig	2021-03-22 20:10:27 UTC
+++ pluginterfaces/base/fplatform.h
@@ -95,7 +95,7 @@
 //-----------------------------------------------------------------------------
 // LINUX
 //-----------------------------------------------------------------------------
-#elif __gnu_linux__ || __linux__
+#elif __gnu_linux__ || __linux__ || defined(__FreeBSD__)
 	#define SMTG_OS_LINUX	1
 	#define SMTG_OS_MACOS	0
 	#define SMTG_OS_WINDOWS	0
@@ -107,7 +107,7 @@
 	#define SMTG_CPU_ARM	__arm__
 	#define SMTG_CPU_ARM_64	__aarch64__
 
-	#include <endian.h>
+	#include <sys/endian.h>
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
 		#define BYTEORDER kLittleEndian
 	#else
