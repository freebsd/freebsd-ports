Index: bridges/source/remote/iiop/unmarshal.cxx
===================================================================
RCS file: /cvs/udk/bridges/source/remote/iiop/unmarshal.cxx,v
retrieving revision 1.4.10.1
diff -u -r1.4.10.1 unmarshal.cxx
--- bridges/source/remote/iiop/unmarshal.cxx	8 Aug 2002 02:49:44 -0000	1.4.10.1
+++ bridges/source/remote/iiop/unmarshal.cxx	28 Jul 2005 12:18:13 -0000
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
 
