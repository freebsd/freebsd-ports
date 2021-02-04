--- basic/source/runtime/methods.cxx.orig	2020-11-22 14:05:28 UTC
+++ basic/source/runtime/methods.cxx
@@ -85,6 +85,7 @@ using namespace com::sun::star::uno;
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <sbobjmod.hxx>
 #include <sbxmod.hxx>
