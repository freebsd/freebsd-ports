--- cjeca32/stdafx.h.orig	2026-04-18 11:09:46 UTC
+++ cjeca32/stdafx.h
@@ -60,7 +60,7 @@
 
 #include "cjeca32.h"
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   #include <PCSC/reader.h>
 #else
   #include "PCSC10.h"
