--- tochnog.h.orig	Sun Feb 11 05:05:27 2001
+++ tochnog.h	Fri Feb  3 15:15:51 2006
@@ -17,12 +17,17 @@
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
-#include <iostream.h>
+#include <iostream>
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
@@ -48,6 +53,8 @@
   VERSION_MACRO,        // mesh for control_macro
   MVERSION              // maximum number of versions, this must be the last item
 }; 
+
+#define TOCHNOG_VERSION "July_25_2002"
 
   // constants
 #define MCHAR 100  // maximum length of names
