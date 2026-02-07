--- src/mips/ffitarget.h.orig	2014-11-08 12:47:24 UTC
+++ src/mips/ffitarget.h
@@ -41,7 +41,7 @@
 #define _MIPS_SIM_ABI32		1
 #define _MIPS_SIM_NABI32	2
 #define _MIPS_SIM_ABI64		3
-#elif !defined(__OpenBSD__)
+#elif !defined(__OpenBSD__) && !defined(__FreeBSD__)
 # include <sgidefs.h>
 #endif
 
