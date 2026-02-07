--- basic/source/runtime/methods.cxx.orig	2022-12-22 00:14:09 UTC
+++ basic/source/runtime/methods.cxx
@@ -95,6 +95,7 @@ using namespace com::sun::star::uno;
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <sbobjmod.hxx>
 #include <sbxmod.hxx>
