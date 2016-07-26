--- SpiralSound/SpiralInfo.h.orig	Wed Nov 22 12:59:01 2006
+++ SpiralSound/SpiralInfo.h	Wed Nov 22 13:00:04 2006
@@ -16,13 +16,15 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
-#include <iostream.h>
+#include <iostream>
 #include <string>
 #include <stdlib.h>
 #include "Sample.h"
 
 #ifndef SpiralINFO
 #define SpiralINFO
+
+using namespace std;
 
 // todo: better place for these util funcs
 float RandFloat(float s=0.0f, float e=1.0f);
