Index: bridges/source/remote/static/stub.cxx
===================================================================
RCS file: /cvs/udk/bridges/source/remote/static/stub.cxx,v
retrieving revision 1.2.26.1
diff -u -r1.2.26.1 stub.cxx
--- bridges/source/remote/static/stub.cxx	8 Aug 2002 02:49:47 -0000	1.2.26.1
+++ bridges/source/remote/static/stub.cxx	28 Jul 2005 12:13:32 -0000
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
 
