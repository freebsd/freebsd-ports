Index: bridges/source/remote/static/proxy.cxx
===================================================================
RCS file: /cvs/udk/bridges/source/remote/static/proxy.cxx,v
retrieving revision 1.3.6.1
diff -u -r1.3.6.1 proxy.cxx
--- bridges/source/remote/static/proxy.cxx	8 Aug 2002 02:49:46 -0000	1.3.6.1
+++ bridges/source/remote/static/proxy.cxx	28 Jul 2005 12:08:44 -0000
@@ -59,14 +59,7 @@
  *
  ************************************************************************/
 #include <assert.h>
-#if defined(SOLARIS) || defined(IRIX)
-#include <alloca.h>
-#elif defined MACOSX
-#include <sys/types.h>
-#include <sys/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
 #include <bridges/remote/proxy.hxx>
 #include <bridges/remote/context.h>
