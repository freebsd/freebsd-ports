--- x11/serverping.cpp.orig	Sat Mar 22 21:55:12 2003
+++ x11/serverping.cpp	Sat Oct 25 21:48:03 2003
@@ -25,8 +25,9 @@
 // code and should be reasonably easy to compile on Windows.
 
 
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <strstream>
+using namespace std;
 #include "utils.h"
 #include "streams.h"
 #include "xetp_basic.h"
