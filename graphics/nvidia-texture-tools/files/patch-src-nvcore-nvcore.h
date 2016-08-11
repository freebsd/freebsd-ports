--- src/nvcore/nvcore.h.orig	2010-05-15 09:12:05 UTC
+++ src/nvcore/nvcore.h
@@ -38,6 +38,9 @@
 #if defined POSH_OS_LINUX
 #	define NV_OS_LINUX 1
 #	define NV_OS_UNIX 1
+#elif defined POSH_OS_FREEBSD
+#	define NV_OS_FREEBSD 1
+#	define NV_OS_UNIX 1
 #elif defined POSH_OS_CYGWIN32
 #	define NV_OS_CYGWIN 1
 #elif defined POSH_OS_MINGW
@@ -158,7 +161,7 @@
 #elif NV_CC_GNUC
 #	if NV_OS_LINUX
 #		include "DefsGnucLinux.h"
-#	elif NV_OS_DARWIN
+#	elif NV_OS_DARWIN || NV_OS_FREEBSD
 #		include "DefsGnucDarwin.h"
 #	elif NV_OS_MINGW
 #		include "DefsGnucWin32.h"
