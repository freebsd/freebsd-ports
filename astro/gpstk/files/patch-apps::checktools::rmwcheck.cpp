--- apps/checktools/rmwcheck.cpp.orig	Wed Jan 19 19:36:30 2005
+++ apps/checktools/rmwcheck.cpp	Thu May 12 15:12:26 2005
@@ -1,12 +1,14 @@
 #pragma ident "$Id: //depot/sgl/gpstk/dev/apps/checktools/rmwcheck.cpp#1 $"
 
+using namespace std;
+#include <ostream>
+
 #include "CheckFrame.hpp"
 
 #include "RinexMetStream.hpp"
 #include "RinexMetData.hpp"
 #include "RinexMetFilterOperators.hpp"
 
-using namespace std;
 using namespace gpstk;
 
 int main(int argc, char* argv[])
