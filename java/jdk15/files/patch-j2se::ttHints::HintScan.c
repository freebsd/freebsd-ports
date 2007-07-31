$FreeBSD$

--- ../../j2se/src/share/native/sun/font/t2k/ttHints/HintScan.c	6 Mar 2007 16:53:10 -0000	1.1.1.2
+++ ../../j2se/src/share/native/sun/font/t2k/ttHints/HintScan.c	31 Jul 2007 04:07:56 -0000
@@ -34,7 +34,7 @@
 
 #include "HintScan.h"
 
-#include "cpu.h" //for fastint 
+#include "Hint.h" //for fastint 
 
 /* copy macros as temporal solution - straightforward including cause compilation issues */
 #define F26Dot6ToFixed(x)        ((x) << 10)
