--- ui/zinf/src/ThemeZip.cpp.orig	2003-09-16 17:36:22 UTC
+++ ui/zinf/src/ThemeZip.cpp
@@ -21,11 +21,12 @@
    $Id: ThemeZip.cpp,v 1.8 2003/09/16 17:36:22 kgk Exp $
 ____________________________________________________________________________*/ 
 
-#include <stdint.h>
 #include <time.h>
 #include <stdio.h>
 #include <ctype.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #ifdef WIN32
 #include <windows.h>
@@ -44,6 +45,7 @@ ________________________________________
 #include <strings.h>
 #endif
 #include <string>
+#include <cstring>
 
 using namespace std;
 #include "zlib.h"
