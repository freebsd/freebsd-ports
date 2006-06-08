--- lib/fractal/DoubleVariables.h.orig	Sat Dec  1 01:27:59 2001
+++ lib/fractal/DoubleVariables.h	Sun Dec 22 06:47:52 2002
@@ -1,7 +1,9 @@
 #ifndef _DOUBLE_VARIABLES_H_
 #   define _DOUBLE_VARIABLES_H_
 
-class ostream;
+#include <iostream>
+using namespace std;
+
 struct DoubleEntry;
 
 class DoubleVariables
