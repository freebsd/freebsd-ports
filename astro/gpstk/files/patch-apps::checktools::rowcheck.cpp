--- apps/checktools/rowcheck.cpp.orig	Wed Jan 19 19:36:30 2005
+++ apps/checktools/rowcheck.cpp	Thu May 12 15:12:26 2005
@@ -1,11 +1,13 @@
 #pragma ident "$Id: //depot/sgl/gpstk/dev/apps/checktools/rowcheck.cpp#1 $"
 
+using namespace std;
+#include <ostream>
+
 #include "CheckFrame.hpp"
 
 #include "RinexObsStream.hpp"
 #include "RinexObsData.hpp"
 
-using namespace std;
 using namespace gpstk;
 
 int main(int argc, char* argv[])
