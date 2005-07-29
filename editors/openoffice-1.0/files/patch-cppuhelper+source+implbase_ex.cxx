Index: cppuhelper/source/implbase_ex.cxx
===================================================================
RCS file: /cvs/udk/cppuhelper/source/implbase_ex.cxx,v
retrieving revision 1.5
diff -u -r1.5 implbase_ex.cxx
--- cppuhelper/source/implbase_ex.cxx	15 Aug 2002 12:36:30 -0000	1.5
+++ cppuhelper/source/implbase_ex.cxx	10 Jul 2005 09:41:00 -0000
@@ -61,11 +61,8 @@
 
 #ifdef SOLARIS
 #include <alloca.h>
-#elif defined MACOSX
-#include <sys/types.h>
-#include <sys/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #include <string.h>
 
