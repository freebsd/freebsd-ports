Index: bridges/source/remote/iiop/dispatch.cxx
===================================================================
RCS file: /cvs/udk/bridges/source/remote/iiop/dispatch.cxx,v
retrieving revision 1.5.14.1
diff -u -r1.5.14.1 dispatch.cxx
--- bridges/source/remote/iiop/dispatch.cxx	8 Aug 2002 02:49:44 -0000	1.5.14.1
+++ bridges/source/remote/iiop/dispatch.cxx	28 Jul 2005 12:17:15 -0000
@@ -58,14 +58,7 @@
  *
  *
  ************************************************************************/
-#if defined(SOLARIS) || defined(IRIX)
-#include <alloca.h>
-#elif defined MACOSX
-#include <sys/types.h>
-#include <sys/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
 #include <osl/diagnose.h>
 
