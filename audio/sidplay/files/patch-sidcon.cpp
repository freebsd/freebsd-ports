--- sidcon.cpp.orig	2002-02-19 19:48:37 UTC
+++ sidcon.cpp
@@ -25,12 +25,18 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
 
 #include <sidplay/sidtune.h>
 #include <sidplay/fformat.h>
 
+using std::cerr;
+using std::cin;
+using std::cout;
+using std::endl;
+using std::flush;
+
 static bool toPSID = true,
     toSIDPLAY = false,
     checkOnly = false,
