--- tochnog.h.orig	Sat Jul 12 13:05:15 2003
+++ tochnog.h	Sat Jul 12 15:29:05 2003
@@ -17,12 +17,25 @@
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
-#include <iostream.h>
+#include <iostream>
+// C++ iostream compatibility stuff
+using std::ios;
+using std::cout;
+using std::cin;
+using std::flush;
+//end iostream compatibility stuff
+
 #include <assert.h>
 #include <ctype.h>
 #include <float.h>
-#include <fstream.h>
-#include <iomanip.h>
+#include <fstream>
+// C++ fstream compatibility stuff
+using std::ifstream;
+using std::ofstream;
+using std::fstream;
+//end fstream compatibility stuff
+
+#include <iomanip>
 #include <math.h>
 #include <limits.h>
 #include <stdio.h>
