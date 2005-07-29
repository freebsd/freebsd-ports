Index: cppu/source/uno/lbenv.cxx
===================================================================
RCS file: /cvs/udk/cppu/source/uno/lbenv.cxx,v
retrieving revision 1.23
diff -u -r1.23 lbenv.cxx
--- cppu/source/uno/lbenv.cxx	13 Aug 2002 15:07:09 -0000	1.23
+++ cppu/source/uno/lbenv.cxx	10 Jul 2005 09:32:20 -0000
@@ -93,10 +93,6 @@
 #include <stdio.h>
 #ifdef SOLARIS
 #include <alloca.h>
-#elif defined MACOSX
-#include <sys/malloc.h>
-#else
-#include <malloc.h>
 #endif
 #include <hash_map>
 #include <vector>
