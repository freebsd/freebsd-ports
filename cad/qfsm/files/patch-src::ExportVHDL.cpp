--- src/ExportVHDL.cpp.orig	Sat Mar  6 22:32:02 2004
+++ src/ExportVHDL.cpp	Tue Mar 16 23:53:08 2004
@@ -16,7 +16,8 @@
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <qregexp.h>
 
 #include "ExportVHDL.h"
