--- src/Main/metar_main.cxx.orig	Sun Nov 20 19:38:38 2005
+++ src/Main/metar_main.cxx	Sun Nov 20 19:39:05 2005
@@ -20,6 +20,7 @@
 //
 // $Id: metar_main.cxx,v 1.10 2005/10/25 16:28:46 ehofman Exp $
 
+#include <time.h>
 #include <iomanip>
 #include <sstream>
 #include <string.h>
