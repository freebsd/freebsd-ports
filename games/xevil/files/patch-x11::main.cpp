--- x11/main.cpp.orig	Sat Mar 22 20:52:14 2003
+++ x11/main.cpp	Sat Oct 25 21:47:04 2003
@@ -33,7 +33,8 @@
 #include <X11/Xos.h>
 }
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "utils.h"
 #include "neth.h"
