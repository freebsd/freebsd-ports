--- apps/checktools/ficcheck.cpp.orig	Wed Jan 19 19:36:30 2005
+++ apps/checktools/ficcheck.cpp	Thu May 12 15:12:26 2005
@@ -1,11 +1,13 @@
 #pragma ident "$Id: //depot/sgl/gpstk/dev/apps/checktools/ficcheck.cpp#1 $"
 
+using namespace std;
+#include <ostream>
+
 #include "CheckFrame.hpp"
 
 #include "FICStream.hpp"
 #include "FICData.hpp"
 
-using namespace std;
 using namespace gpstk;
 
 int main(int argc, char* argv[])
