--- lib/fractal/PrintArg.h.orig	Sat Dec  1 01:27:59 2001
+++ lib/fractal/PrintArg.h	Sun Dec 22 07:00:54 2002
@@ -1,9 +1,11 @@
 #ifndef _PRINT_ARG_H_
 #   define _PRINT_ARG_H_
 
+#include <iostream>
+using namespace std;
+
 class ComplexVariables;
 class DoubleVariables;
-class ostream;
 
 class PrintArg
 {
