--- src/Puzzle.cpp.orig	Sat Nov  2 02:56:14 2002
+++ src/Puzzle.cpp	Sat Nov  2 02:57:54 2002
@@ -26,6 +26,7 @@
 
 #include "Puzzle.h"
 
+#include <iostream>
 #include <fstream>
 #include <stdexcept>
 #include <stdio.h>
@@ -35,6 +36,8 @@
 #include "String.h"
 
 #include "Namespace.h"
+
+using namespace std;
 
 NAMESPACE_OPEN
 
