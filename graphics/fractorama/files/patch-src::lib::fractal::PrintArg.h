--- lib/fractal/PrintArg.h.orig	Fri Oct 24 22:33:26 2003
+++ lib/fractal/PrintArg.h	Tue Mar  2 23:09:27 2004
@@ -1,7 +1,8 @@
 #ifndef _PRINT_ARG_H_
 #   define _PRINT_ARG_H_
 
-class ostream;
+#include <iostream>
+using namespace std;
 
 class PrintArg
 {
