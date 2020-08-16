--- basic/source/runtime/methods.cxx.orig
+++ basic/source/runtime/methods.cxx
@@ -84,6 +84,7 @@ using namespace com::sun::star::uno;
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <sbobjmod.hxx>
 #include <sbxmod.hxx>
