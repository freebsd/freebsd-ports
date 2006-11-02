--- apps/checktools/ficacheck.cpp.orig	Wed Jan 19 19:36:30 2005
+++ apps/checktools/ficacheck.cpp	Thu May 12 15:12:26 2005
@@ -1,11 +1,14 @@
 #pragma ident "$Id: //depot/sgl/gpstk/dev/apps/checktools/ficacheck.cpp#1 $"
 
+using namespace std;
+
+#include <ostream>
+
 #include "CheckFrame.hpp"
 
 #include "FICAStream.hpp"
 #include "FICData.hpp"
 
-using namespace std;
 using namespace gpstk;
 
 int main(int argc, char* argv[])
