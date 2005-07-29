Index: cppu/source/typelib/typelib.cxx
===================================================================
RCS file: /cvs/udk/cppu/source/typelib/typelib.cxx,v
retrieving revision 1.14.10.1
diff -u -r1.14.10.1 typelib.cxx
--- cppu/source/typelib/typelib.cxx	9 Aug 2002 02:30:50 -0000	1.14.10.1
+++ cppu/source/typelib/typelib.cxx	10 Jul 2005 09:13:22 -0000
@@ -71,12 +71,6 @@
 #include <stdarg.h>
 #include <stdlib.h>
 #include <string.h>
-#ifdef MACOSX
-#include <sys/types.h>
-#include <sys/malloc.h>
-#else
-#include <malloc.h>
-#endif
 #if defined(SOLARIS) || defined(IRIX)
 #include <alloca.h>
 #endif
