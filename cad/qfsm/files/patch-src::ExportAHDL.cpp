--- src/ExportAHDL.cpp.orig	Sat Mar  6 22:28:50 2004
+++ src/ExportAHDL.cpp	Tue Mar 16 23:43:50 2004
@@ -16,7 +16,8 @@
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <qregexp.h>
 
 #include "ExportAHDL.h"
