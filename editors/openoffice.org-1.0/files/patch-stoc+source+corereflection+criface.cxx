Index: stoc/source/corereflection/criface.cxx
===================================================================
RCS file: /cvs/udk/stoc/source/corereflection/criface.cxx,v
retrieving revision 1.6
diff -u -r1.6 criface.cxx
--- stoc/source/corereflection/criface.cxx	3 May 2001 13:56:57 -0000	1.6
+++ stoc/source/corereflection/criface.cxx	28 Jul 2005 12:24:08 -0000
@@ -60,14 +60,7 @@
  ************************************************************************/
 
 #include <sal/config.h>
-#ifdef SAL_UNX
-#if !(defined(MACOSX) || defined(NETBSD) || defined(FREEBSD))
-#include <alloca.h>
-#endif
-#endif
-#ifndef MACOSX
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 #ifndef _RTL_ALLOC_H_
 #include <rtl/alloc.h>
 #endif
