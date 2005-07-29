Index: cppuhelper/source/tdmgr.cxx
===================================================================
RCS file: /cvs/udk/cppuhelper/source/tdmgr.cxx,v
retrieving revision 1.4
diff -u -r1.4 tdmgr.cxx
--- cppuhelper/source/tdmgr.cxx	15 Oct 2001 16:07:59 -0000	1.4
+++ cppuhelper/source/tdmgr.cxx	10 Jul 2005 09:41:51 -0000
@@ -60,7 +60,7 @@
  ************************************************************************/
 
 #ifndef MACOSX
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #ifdef SOLARIS
 #include <alloca.h>
