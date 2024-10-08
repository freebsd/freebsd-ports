--- cjeca32/stdafx.h.orig	2024-10-06 15:05:20 UTC
+++ cjeca32/stdafx.h
@@ -59,7 +59,7 @@
 #include "ntstatus.h"
 
 #include "cjeca32.h"
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   #include <PCSC/reader.h>
 #endif
 
