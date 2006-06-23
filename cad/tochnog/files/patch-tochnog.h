--- tochnog.h	2002/06/01 13:50:03	1.1.1.1
+++ tochnog.h	2002/08/01 08:44:35	1.3
@@ -17,12 +17,16 @@
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
-#include <iostream.h>
+// C++ headers
+#include <iostream>
+#include <fstream>
+#include <iomanip>
+using namespace std;
+
+// C headers
 #include <assert.h>
 #include <ctype.h>
 #include <float.h>
-#include <fstream.h>
-#include <iomanip.h>
 #include <math.h>
 #include <limits.h>
 #include <stdio.h>
@@ -49,6 +53,8 @@
   MVERSION              // maximum number of versions, this must be the last item
 }; 
 
+#define TOCHNOG_VERSION "July_25_2002"
+
   // constants
 #define MCHAR 100  // maximum length of names
 #define MDIM 3 // maximum number of space dimensions
