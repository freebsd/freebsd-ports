Index: bridges/source/remote/urp/urp_dispatch.cxx
===================================================================
RCS file: /cvs/udk/bridges/source/remote/urp/urp_dispatch.cxx,v
retrieving revision 1.8.2.1
diff -u -r1.8.2.1 urp_dispatch.cxx
--- bridges/source/remote/urp/urp_dispatch.cxx	8 Aug 2002 02:49:48 -0000	1.8.2.1
+++ bridges/source/remote/urp/urp_dispatch.cxx	28 Jul 2005 12:15:51 -0000
@@ -58,14 +58,7 @@
  *
  *
  ************************************************************************/
-#if defined(SOLARIS) || defined(IRIX)
-#include <alloca.h>
-#elif MACOSX
-#include <sys/types.h>
-#include <sys/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
 #include <osl/mutex.hxx>
 #include <osl/diagnose.h>
