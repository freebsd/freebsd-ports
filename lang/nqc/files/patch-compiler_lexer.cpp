--- compiler/lexer.cpp.orig	2013-11-03 11:24:46.670522000 +0000
+++ compiler/lexer.cpp
@@ -11,6 +11,7 @@
 #define YY_FLEX_MINOR_VERSION 5
 
 #include <stdio.h>
+#include <unistd.h>
 
 #if defined(__MWERKS__) && !__MACH__ && !YY_NEVER_INTERACTIVE
 #include <unix.h>
