--- lib/fractal/PrintArg.h.orig	Sun Feb  2 08:45:00 2003
+++ lib/fractal/PrintArg.h	Mon Apr 28 04:26:13 2003
@@ -1,10 +1,12 @@
 #ifndef _PRINT_ARG_H_
 #   define _PRINT_ARG_H_
 
+#include <iostream>
+using namespace std;
+
 class ComplexVariables;
 class DoubleVariables;
 class ColorEnvironment;
-class ostream;
 
 class PrintArg
 {
