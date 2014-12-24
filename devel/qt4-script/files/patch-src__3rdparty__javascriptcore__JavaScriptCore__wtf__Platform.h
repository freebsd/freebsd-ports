--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/Platform.h.orig	2014-04-10 22:37:12.000000000 +0400
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/Platform.h	2014-12-20 07:17:24.000000000 +0300
@@ -336,7 +336,6 @@
 /* CPU(MIPS) - MIPS, any version */
 #if (defined(mips) || defined(__mips__) || defined(MIPS) || defined(_MIPS_))
 #define WTF_CPU_MIPS 1
-#include <sgidefs.h>
 #if defined(__MIPSEB__)
 #define WTF_CPU_BIG_ENDIAN 1
 #endif
