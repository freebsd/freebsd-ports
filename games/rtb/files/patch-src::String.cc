--- src/String.cc.orig	Fri Nov 12 22:04:38 2004
+++ src/String.cc	Tue Jan 11 02:28:46 2005
@@ -21,12 +21,13 @@
 #include <config.h>
 #endif
 
-#include <string.h>
+#include <cstring>
 #include <iostream>
 //#include <strstream>
 #include <iomanip>
-#include <stdlib.h>
-#include <ctype.h>
+#include <cstdio>
+#include <cstdlib>
+#include <cctype>
 
 using namespace std;
 
