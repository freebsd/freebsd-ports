--- src/main.cpp.orig	Sun Mar  7 01:12:13 2004
+++ src/main.cpp	Wed Mar 17 00:12:23 2004
@@ -16,8 +16,9 @@
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
-#include <stdlib.h>
-#include <iostream.h>
+#include <cstdlib>
+#include <iostream>
+using namespace std;
 #include <qtranslator.h>
 #include <qapplication.h>
 #include <qstring.h>
