--- ui/zinf/src/ThemeZip.cpp.orig	Wed Sep 17 02:36:22 2003
+++ ui/zinf/src/ThemeZip.cpp	Mon Feb 16 13:39:03 2004
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
