--- ccx_1.2/src/spooles.h.orig	Sat Dec 25 01:58:09 2004
+++ ccx_1.2/src/spooles.h	Sat Dec 25 13:25:29 2004
@@ -24,7 +24,9 @@
 #include <misc.h>
 #include <FrontMtx.h>
 #include <SymbFac.h>
+#ifdef USE_MT
 #include <MT/spoolesMT.h>
+#endif
 
 /* increase this for debugging */
 #define DEBUG_LVL	0
